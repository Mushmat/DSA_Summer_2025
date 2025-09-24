// given a grid of n x m
// 0 means empty, 1 means cell has fresh orange, 2 means cell has rotten oranges
// what is the minimum time to rot all oranges?
// for a rotten orange, it can rot all fresh oranges at its up down left right in unit time
// at start, all rotten oranges rot its neighbors simultaneously

// if after every traversal, there are oranges that are still fresh (that means it was not reachable by rotten oranges)
// then rottening is not possible and hence return -1 as the answer

// we get the intuition that we should use BFS since it traverses level wise

// define the queue and add the rotten orange coordinated to the queue
// keep a vis 2d matrix and mark the rotten oranges as 2
// keep a variable time with the queue to map at what time each cell was rottened
// pick out the rotten orange from queue and visit its neighbors
// if theres a fresh orange, put this in queue with a time increment by 1
// and also rotten it in visited array (mark it 2)
// repeat
// in last check whether all fresh oranges were rottened or not, if not, return -1

class Solution{
    public:
    int orangesRotting(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q; // stores row, col, time
        vector<vector<int>> vis;

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first();
            int c = q.front().first.second();
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i = 0; i< 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; 
                }
            }

        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return tm;
    }
}

// SC: O(N x M)
// TC: O(N x M)
