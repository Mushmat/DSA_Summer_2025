// return the no of connected components
// given a grid of size n * m (n rows, m columns) and 0 means water, 1 means land
// task find no of islands

// this is similar to the problem where we touch the starting node, and each starting node is an island
// we can simply apply any traversal technique to a starting point, keep a vis
// take a queue, and insert the first vertex 
// take a same size 2d array to mark the visited nodes
// mark the first vertex visited
// now do bfs:
// pick the element from the queue and travel to all the neighbors
// check all the eight boundaries and get the neighbors (those who are 1s)

class Solution{
    private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first();
            int col = q.front().second();
            q.pop();

            // traverse in neighbors and mark them if a land
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

    public:
    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
}

// SC: O(n^2) + O(n^2) queue 
// TC: O(N^2)