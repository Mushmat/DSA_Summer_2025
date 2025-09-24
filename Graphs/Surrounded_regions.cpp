// Replace Os with Xs
// Given a matrix N x M, replace O with X that are surrounded by X
// it is surrounded by X if there is X from all four sides (left, right, top, bottom)
// diagonals are not considered
// A group of Os must be surrounded by X from all four sides to be replaced
// If an O is on the border, it is not surrounded
// If a set of Os is connected to an O on the border, it is not surrounded, it cant be replaced

// Start from the boundary Os, apply DFS to mark all connected Os
// None of these marked Os can be replaced ever
// Similarly do this for all boundary Os
// Finally, replace all unmarked Os with Xs

// Create a corresponding visited matrix to keep track of marked Os, initally all 0
// Traverse the boundary of the matrix, check whether the element is 0 or not and unvisited
// whenever you find an unvisited O, apply DFS to mark all connected Os as visited
// after doing this for all boundary Os that are unvisited, mark all the unvisited Os in the original matrix as Xs

class Solution{
    private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delRow[], int delCol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == '0'){
                dfs(nrow, ncol, vis, mat, delRow, delCol);
            }
        }
    }
    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<int>> vis(n, vector<int> (m, 0));
        // traverse first row and last row
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && mat[0][j] == '0'){ // first row
                dfs(0, j, vis, mat, delrow, delcol);
            }
            if(!vis[n-1][j] && mat[n-1][j] == '0'){ // last row
                dfs(n-1, j, vis, mat, delrow, delcol);
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i][0] && mat[i][0] == '0'){ // first column
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            if(!vis[i][m-1] && mat[i][m-1] == '0'){ // last column
                dfs(i, m-1, vis, mat, delrow, delcol;);
            }
        }

        for(int i =0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && mat[i][j] == '0'){
                    mat[i][j] = 'X';
                }
            }
        }
    }
};

// TC: O(N*M) + O(N*M) + O(N*M) ~ O(N*M)
// SC: O(N*M) + O(N*M) ~ O(N*M) (visited matrix + recursive stack space)