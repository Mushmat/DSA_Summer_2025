// minimum path sum in grid
// ninjaland is a country in the shape of a 2D dimensional grid GRID and N rows and M columns
// each point on the grid has some cost associated with it
// find a path from top left to bottom right which minimizes the sum of the cost of all numbers along the path. tell the minimum sum of the path
// again can only move bottom or right

//we need to explore all paths hence we will use recursion

// write the recursion of (i,j) with ith row and jth column
// therefore f(n-1, m-1) returns cost from 0,0 to n-1, m-1
// base case is 0,0: return a[0][0] // the origin has to be in the path
// i < 0, j < 0; return INT_MAX (such that this path gets max cost, and we never take this, as this is out of bounds)
// other than this
// up = take this number and then find out path till this cell, which is a[i][j] + f(i-1, j)
// left = similarly, a[i][j] + f(i, j-1);
// easy recursion bruh, simply take the minimum now

// as we have seen there will be overlapping subproblems, simply apply memoization
// and then tabulation and space optimization

// Memoized SOLUTION

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j ==0) return grid[i][j];
    if(i < 0 || j < 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + f(i-1, j, grid);
    int left = grid[i][j] + f(i, j-1, grid);
    return dp[i][j] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid){
    int n =  grid.size();
    int m =  grid[0].size();
    vector<vector<int>> dp(0, vector<int> (m, -1));
    return f(n-1, m-1, grid, dp);
}


// TABULATION

int minSumPath(vector<vector<int>> &grid){
    int n =  grid.size();
    int m =  grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) dp[i][j] == grid[i][j];
        }
        else{
            int up = grid[i][j];
            // requiring previous row's j column
            if(i > 0) up += dp[i-1][j];
            else up += 1e9; // its out of bounds


            int left = grid[i][k];
            // current row's j-1 column
            if(j > 0) left += dp[i][j-1];
            else left += 1e9;

            dp[i][j] = min(up, left);
        }
    }

    return dp[n-1][m-1];

}

// SPACE OPTIMIZATION

int minSumPath(vector<vector<int>> &grid){
    int n =  grid.size();
    int m =  grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    vector<int> prev(m, 0);
    for(int i = 0; i < n; i++){
        vector<int> cur(m,0);
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) cur[j] == grid[i][j];
        }
        else{
            int up = grid[i][j];
            // requiring previous row's j column
            if(i > 0) up += prev[j];
            else up += 1e9; // its out of bounds


            int left = grid[i][k];
            // current row's j-1 column
            if(j > 0) left += cur[j-1];
            else left += 1e9;

            cur[j] = min(up, left);
        }
        prev = cur;
    }
    

    return prev[m-1];

}