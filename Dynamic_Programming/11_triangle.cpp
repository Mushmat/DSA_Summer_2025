// given a triangular array. return the minimum path sum to reach from the top to the bottom row
// the triangle array has N rows, and ith row, where i is in 0 to N, will have i+1 elements
// you can move only to the adjacent number of row below each step. for example, if you are at index j, in row i, then you can move to i or i + 1 index in row j+1

// here the starting point is fixed
// but the ending point might vary
// we have to reach the last row, but we can reach to any cell of the last row

// since there is un-uniformity in the cells, we cannot use greedy
// so lets use recursion to travel to all the paths

// in all the previous problems, we had the ending point as n-1, m-1
// here the end is variable
// so this time, we will not start from the end

// we will start from f(0,0)
// where f(0,0) signifies the min path sum from 0,0 to last row. (it can be any cell in the last row)
// in the recurrence,
// the base case will be the destination (the n-1th row)
// if(i ==  n-1) then return a[n-1][j]; as we will have to add that last cell to our answer
// for any other i j, take the current value and figure out answer in down, and answer diagonally
// down = a[i][j] + f(i+1, j)
// diagonal = a[i][j] + f(i+1, j+1);
// and then simply min (down, diagonal)

// since yes there will be overlapping subproblems
// so we can memoizze, then tabulize, and then space optimize

// in tabulation we will start from n-1, as our base case is that only
// for(j = 0; j < n; j++)
// dp[n-1][j] = a[n-1][j]; // take the last cell
// then start from n-2, and go till 0
// for each i (the number of rows), there will be i+1 columns. 0th row has 0th column (count 1 colum)

int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp){

    if(i == n-1) return triangle[n-1][j];
    if(dp[i][j] != -1) return dp[i][j];
    int d = triangle[i][j] + f(i+1, j, triangle, n, dp);
    int dg = triangle[i][j] + f(i+1, j+1, triangle, n, dp);

    return dp[i][j] = min(d, dg);

}


int minimumPathSum(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return f(0,0, triangle, n);
}


// TABULATION:

int minimumPathSum(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n,0));

    for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int d = triangle[i][j] + dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(d, dg);
        }
    }

    return dp[0][0];
}

// SPACE OPTIMIZED
int minimumPathSum(vector<vector<int>> &triangle, int n){
    vector<int> front(n,0), cur(n,0);

    for(int j = 0; j < n; j++) front[j] = triangle[n-1][j];
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int d = triangle[i][j] + front[j];
            int dg = triangle[i][j] + front[j+1];
            cur[j] = min(d, dg);
        }
        front = cur;
    }

    return front[0];
}
