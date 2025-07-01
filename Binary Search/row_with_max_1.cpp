// Binary search on 2d arrays
// find the row with max number of 1s from a given 2d matrix with only 0s and 1s
// every row is sorted
// in case where multiple rows with max 1s are there, return the row with min index

// brute is to go to every row and check for the number of ones
// whose TC will be O(n * m)

// think every row as an individual array
// you just need to figure out the first one
// once that is found, the count of 1s can be determined since the array is sorted and u know the size of row and first occurence
// to find the find occurence, we can simply use BS to get lower_bound(1) or upper_bound(0)
// can do for every row individually
// 