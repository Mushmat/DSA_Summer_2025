// maximum path sum
// given an N x M matrix filled with integer numbers
// find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row
// from a cell in a row, you can move to another cell directly below that row, or diagonally brlow left or right.
// that is from i,j; you can go to i+1,j
// or i+1, j-1
// or i+1, j+1

// again cannot use greedy as values are not uniform
// so again we need to use recursion

// the only concern here is that the starting point is not the same
// f(n-1,0) is the max path sum if we end at 0th column. f(n-1, 1) if we end at 1st column in the last row
// so for m columns, call for every n-1 and jth column
// f(n-1, j)
// each of these gives us a max path sum
// so take max of all these

// so we will start from n-1 and go up till 0th row

// f(i, j) -> max path sum to reach i,j from any cell in the 0th row
// starting from last row, the destination is the 0th row
// other base case is the out of bounds areas
// here out of bounds are when col < 0 or col >= n
// if(j < 0 || j > = m) return -1e9;
// if(i == 0) return a[0][j];
// int straight = a[i][j] + f(i-1, j)
// int left = a[i][j] + f(i-1, j-1)
// int right = a[i][j] + f(i-1, j+1)
// and then return max (straight, left, right)

// these are followed by memoization, tabulation, space optimization

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = matrix[i][j] + dp[i-1][j];
            int ld = matrix[i][j];
            if(j-1 > 0) ld += dp[i-1][j-1];
            else ld += -1e8;
            int rd = matrix[i][j];
            if(j+1 < m) rd += dp[i-1][j+1];
            else rd += -1e8;
            dp[i][j] = max(u, ld, rd);
        }
    }

    int maxi = -1e8;
    for(int j = 0; j < m; j++){
        maxi = max(maxi, dp[n-1][j]);
    }

    return maxi;

}