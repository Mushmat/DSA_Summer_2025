// dp on grids include many problems
// eg count paths
// count paths with obstacles
// minimum path sums
// max path sums (under constraint)
// triangle problems etc

// Total unique paths question:
// you are at the top left cell of an n x m matrix (0,0) A
// destination is the bottom right cell of the same matrix (m-1, n-1) B
// task is to find the total number of unique paths from point A to point B
// you can move right or down only

// since we need to check all possible ways, we will apply recursion
// index are i,j representing rows and columns

// f(i,j) gives the number of unique ways to reach i, j from 0,0
// base case: if destination is reached return 1, else return 0
// destination (starting from m-1, n-1) is 0,0
// so if i & j == 0, return 1
// on returning 1, it gets counted (count ways)
// another base case is exceeding the boundary (in the up direction or left direction)
// so if i < 0 or j < 0, return 0

// now do all stuffs
// go up (i-1, j)
// go left (i, j-1)

// sum all the ways
// return up + left

// right now the complexity if 2^(mxn) since we are taking all paths
// so lets memoize it (since we will have overlapping subproblems)

// which parameters are chaning? i & j
// max value of i is m-1, max value of j is n-1
// therefore declare array of sizes m and n
// dp[m][n]

// now it can be tabulized as well
// we can start with the bottom up approach
// dp[0][0] = 1 (the first base case)
// the states here are i j
// first value of i will be 0
// for this i value, j value can be 0, 1, 2, 3,.... n-1
// therefore two for loops
// and then copy the recurrence from memoization

// now we can do space optimization
// we are only using previous row and previous column
// nothing else is needed

