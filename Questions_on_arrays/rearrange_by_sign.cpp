// Given an array of n elements where n is even.
// There are n/2 positive elements and n/2 negative elements
// Rearrange those by sign. as in: + - + - + - + - + - + - ...
// eg {3 1 -2 -5 2 -4} can be rearranged in {3 -2 1 -5 2 -4}
// Brute:
// Take an empty array positive, and an empty array negative
// Iterate the entire array and put positives in positive array, negatives in negative array
// put all the positive elements at the even indices, and all negative elements at the odd indices
// arr[2*i] = pos[i] ; arr[2*i+1] = neg[i]
// Both TC and SC are O(2N)

// Optimal:
// Take an answer array
// We know all +ves are at even indices
// and -ves are at odd indices
// Iterate in the original array, find the first positive element and put it at 0th index, next positive element at 2nd index and so on.
// For negative elements, start with 1st index, 3rd index, and so on...
// TC: O(N) and SC: O(N)

