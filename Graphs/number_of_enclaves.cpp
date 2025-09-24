// Given N x M binary matrix
// 0 represents a sea cell and 1 represents a land cell
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid
// Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves

// you cannot move out from a boundary of the matrix if you are unable to reach to a land cell (that is 1) which is on the boundary
// therefore you can only move out of the boundary if you are connected to a land cell on the boundary
// count the number of lands which are not connected to any land cell on the boundary
// something that is connected to the boundary cannot be an enclave hence cannot be the answer

// figure out the boundary 1s and connect all the 1s connected to the boundary 1s
// after that the remaining 1s are the answer
// let us use BFS this time (we already used DFS in the previous problem - Surrounded regions)

// keep all the boundary 1s in the queue and mark them visited, then take out each element from the queue and check for its unvisited 1 neighbours

class Solution {
    public:
    int numberOfEnclaves(vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m] = {0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // first row, last row, first column, last column
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, +1, 0};
            int delCol[] = {0, +1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        
        return count;
    };

    // TC: O(N*M) + O(N*M) + O(N*M) ~ O(N*M)
    // SC: O(N*M) + O(N*M) ~ O(N*M) (visited matrix + queue)