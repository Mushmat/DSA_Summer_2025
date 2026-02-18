// count squares with all 1s in a nxm matrix
// here we need all the squares that are there in a matrix
// for each size of squares, determine how many squares can be

// create a similar size dp array
// dp[i][j] in this new matrix will tell how many squares END at i,j. which means the square's right bottom is at i,j
// after filling this DP matrix completely, just return the sum of all the elements

int countSquares(int n, int m, vector<vector<int>> &arr){
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int j = 0; j <m; j++) dp[0][j] = arr[0][j];
    for(int i = 0; i < n; i++) dp[i][0] = arr[i][0];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(arr[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])); // checks if everything in diagonal and previous is 1 or not
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += dp[i][j];
        }
    }

    return sum;
}