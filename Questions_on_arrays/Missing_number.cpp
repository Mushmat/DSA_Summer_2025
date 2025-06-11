// Given a number N
// Given an array of size n-1 and contains numbers from 1 to N
// Your job is to find the missing number
// Eg if n = 5 and array is [ 1 2 4 5], then the missing number is 3
// So return 3

// Brute force:
// You know the numbers are from 1 to n
// Check each number
// Is 1 there, yes. Is 2 there, yes. Is 3 there, no. Therefore 3 is missing. 
// Simple linear search 
// But this takes O(n^2) time. so not efficient, space is O(1)

// Better:
// We can use hashing
// Declare an array of size n+, the hash array (providing us the nth index)
// Iterate each index and store each number's presence
// Reiterate from 1 to 5 index to check which index is not marked (indicating number not present)
// Time Complexity here is O(2n) which is better than n^2 and space complexity is O(N)

// Optimal:
// You have N, and you have all the numbers in the array
// Using N, take out the sum of the first N natural numbers.
// Since array has all the numbers from 1 to N, except one. The sum would help
// Sum the numbers of the array
// Decrease the array sum from the sum of first n natural numbers
// The resultant is the missing number
// Simple
// TC here is O(n) and SC is O(1) which is the better

