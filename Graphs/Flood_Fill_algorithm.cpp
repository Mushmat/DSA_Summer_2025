// given a matrix (can be 0s 1s 2s 3s anynumbers)
// given a starting row sr, starting column sc
// initial color of that = 1 say
// whoever is connected to this 1, and has the same color 1 (only in 4 directions), for them:
// change the color to newColor (2 here), change all the colors to 2 whoever is connected to the node sr sc (that is, have same intial color ONLY)
// keep coloring the 4 directional nodes by this way

class Solution{
    private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int ini){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol< m && image[nrow][ncol] == ini && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol);
            }
        }
        
    }

    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    }
}

// Both SC and TC: O(N x M)