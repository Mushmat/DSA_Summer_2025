// last DP on grids problems
// Ninja has a grid of size R x C. Each cell of the grid contains some chocolates
// NInja has two friends Alice and Bob. and he wants to collect as many chocoaltes as possible with the help of his friends
// Initially, Alice is in the top-left position i.e. (0,0) and Bob is in the top right place, (0, C-1)
// Each of them can move from their current cell to the cells just below them. When anyone pased from any cell, he will pick all chocolates in it
// and the number of chocolates will become zero

// If both stay in the same cell, only one of them will pick chocoltes in it.

// If alice or bob is at i,j, then they can move to down, left diagonal, right diagonal. They will always stay inside the GRID

// find the max number of chocolates ninja can collect with the help of his friends

// here we have a fixed starting point and a variable ending point
// alice starts at 0,0 and bob at 0, m-1
// we need to take all paths by alice + all paths by bob
// we need to make sure alice and bob move together
// if theres a common cell, we have to consider it ONLY ONCE
// for that, we will try to write a recursion together

// express everything in terms of i1 j1 i2 j2 (1 for alice, 2 for bob)
// then write down all the base cases
// next explore all the paths
// and then return the max sum possible

// since we have a fixed starting point, start from their in the recursion
// f(0,0,0,m-1) // both alice and bob position
// f(i1, j1, i2, j2) is the recursion
// base cases are:
// out of bounds is one of them. 
// if boundary is crossed, that path is not considered. so take -1e9 it will never be counted
// another is when we reach the last row
// if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8
// for the destination base case,
// we know that both of the players will reach the end row at the same time, because at every step our player moves to the next row
// therefore instead of keeping i1 i2, just keep i. because i is same
// so now f is f(i, j1, j2)
// if(i == n-1){
// if( j1 ==  j2) return only once
// otherwise return a[i][j1] + a[i][j2] // return for both as they are at different places
// now explore all the paths in down, left diag down, right diag down
// for n movement of alice, there are n movement of bob each. so we have to try n x n combinations
// so we can maintain a change in column array dj and simply apply it

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= 2) return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j2];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    // explore all paths simulataneously
    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= +1; dj1++){
        for(int dj2 = -1; dj2 <= +1; dj2++ ){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += f(i+1, j1 +dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return f(0,0,c-1,r,c,grid, dp);
}
/// TABULATION AND SPACE OPTIMIZATION FOLLOWS