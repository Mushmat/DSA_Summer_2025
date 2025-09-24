// Given a 0/1 grid of nxm, find the distance of the nearest 1 in the grid for each cell. distance is calculated as [i1 - i2] + [j1 -j2]
// for each element write the distance to the nearest 1 in another matrix, and return that matrix
// if the element is itself a 1, then the distance to nearest 1 is 0
// there are no diagonal distance calculation, you have to calculate distance by above formula

// we will use bfs
// pick all the initial ones and take one step in all the directions
// reach the zeroes and count the moves to reach them
// in 1 step, we reach all zeroes at a distance 1
// in 2nd step, we reach all zeroes at a distance 2
// and so on

// in a queue, put the initial ones' coordinates, and their distance (0 as they  are already 1)
// mark them visited
// take out the first element, aand travel all four elements
// add 0's coordinates and their distance (increment by one)

class Solution{
    public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
     int n = grid.size();
     int m = grid[0].size();

     vector<vector<int>> vis(n, vector<int>(m,0));
     vector<vector<int>> dist(n, vector<int>(m, 0));
     queue<pair<pair<int, int>, int>> q;

     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                q.push({{i,j}, 0});
                vis[i][j] = 1;
            }
            else{
                vis[i][j] = 0;
            }
        }
     }   
     int drow = {-1,0,1,0};
     int dcol = {0, 1, 0, -1};
     while(!q.empty()){
        int row = q.front().first.first();
        int col = q.front().first.second();
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps+1});
            }
        }
     }
     return dist;
    }
};

// TC: O(N x M);
// SC: O