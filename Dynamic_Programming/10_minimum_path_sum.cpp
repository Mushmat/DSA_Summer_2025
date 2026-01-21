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
// easy recursion bruh