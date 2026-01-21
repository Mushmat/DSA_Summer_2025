// given n x m maze with obstacles
// return the number of paths from 0,0 to m-1,n-1 
// a cell has a value -1 if it has a deadend or blockage
// we can move right, down
// return how many ways?

// it is similar to the last question

// our original recurrence was (in the last ques)
// if i and j are 0, return 1
// if i < 0 , j < 0 return 0
// else call up and call left
// return up + left
// simple top down approach using memoization

// to take care of obstacles, we will simply add one more base case
// if( i >= 0 && j >= 0 && arr[i][j] == -1) return 0
// because there is a blockage

// in the tabulation simply we add the above case again
// everything else stays the same. simply we mark the obstacle paths as invalid

int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat){
    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == -1) dp[i][j] == 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else{
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = (up + left) % mod;
            }
        }
    }

    return dp[n-1][m-1];
}

// above is the tabulized solution