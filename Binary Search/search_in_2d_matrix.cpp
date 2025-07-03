// given a sorted 2d matrix and a target
// find if the given target is in the 2d matrix or not
// return true if there

// one way to do this is
// first check the first and last element of all rows to check whether the target can lie between them or not
// once the row is found in which the element can be there, apply binary search in that array to find the target
// if the target is not in that row, return false
// if a target does not lie in a given row, move down to check in other rows
// TC: O(n) + log m
// SC: O(1)

// We can still optimize this
// The entire matrix is sorted
// we can hypothetically try to flatten this matrix into a 1D array
// such that it becomes a 1D array and then simple BS can be performed
// but flattening it in reality would take much time
// we will get the low as 0, high as (n x m) - 1, that is the number of elements - 1
// get mid. now if we can map this 1D mid back to the 2D matrix, we can apply BS Easily
// to convert the index into a 2D coordinate:
// to get row number: index / m
// to get column numbeer: index % m
// m is the number of columns
// therefore low = 0, high = n x m - 1
// start BS
// get mid
// then row = mid / m
// then column = mid % m
// if(mat[row][column] == target) return true
// else if ( mat[row][col] < target) low = mid + 1
// else high = mid - 1
// again compute 2d coordinates and do

// if not found, return false
// TC: O(log (n x m))

// now a different variation:
// given a matrix, Not sorted, and given a target. if target is in matrix, return its row and col
// the matrix entirely is not sorted whereas each row and each column in itself is sorted
// the most optimum solution to this is:

// if we stand at the last column of the first row, observe that the elements below are increasing and the elements to its left are decreasing
// eliminate the row number or the column number in which the number cannot be there
// therefore
/*

row = 0, col = m - 1
while(row < n && col >= 0){
    if(mat[row][col] == target) return {row, col}
    else if(mat[row][col] < target) row ++
    else col--;
}
return{-1,-1}

*/

// TC: O(n + m)