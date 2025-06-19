// Rotate the square matrix by 90 degree clockwise

// Brute:
// Create an answer matrix of n x n size
// Pick each element and place it at its correct place
// first row --> last column
// second row --> second last column
// third row --> third last column
// fourth row --> fourth last column ....
// i -> (n-1) - i
// for every i,j --> j, (n-1) - i
// O(N^2) space used

// Optimal:
// We should solve the problem in the given matrix itself
// Observe that each column becomes a row in reverse order, in the answer
// Therefore, transpose the matrix
// reverse each row
// and that is the answer
// How to transpose? --> All the diagonals stay at their place
// other elements swap. 0,1 --> 1,0 etc
// therefore go from i = 0 to 2 only, since it swaps other elements also
// j = i+1 to n-1
// after transpose, pick every row and reverse it
// TC: O(n^2) and no space used
