// Given an array of integers
// Find the longest consecutive sequence
// return the length of it

// Brute:
// Pick an element x and look for x+1, x+2, till the end we can find
// Let longest = 1, and iterate through the array
// for an element x, find x+1 in the array. If found, repeat
// If not, then move the iterator
// If x+1 is found, counter++, and when there is no x+i left, longest = counter and counter = 1 again
// This takes O(n^2) time

// Better:
// Sort the array
// assume longest = 1
// keep track of lastSmaller = last smallest guy we say = INT_MIN
// initialize cntCurrent = 0
// Start the iteration
// lastSmaller = first element
// Move to the next element, if the lastSmaller is one less than the current element, then take the current element and increase the count
// Else move ahead
// Do this until the lastSmaller becomes much smaller than the current element. At that time, store the cntCurrent as longest and cntCurrent as 1 again
// Doing this find the maximum value of longest, which is the answer

// Optimal:
// Only optimal under constraints
// Put every element into a set data structure (unordered_set)
// Start iterating element by element in the set DS. 
// For any element, look for element - 1, if that is in the array, that means element is not the starting point of the sequence, hence we dont start from the element
// By this, look for the element that starts the sequence
// When you get the element which is the starting element, now search for x+1, x+2... and store the longest
// Therefore we avoid checking redundant elements. If an element is in the middle of the sequence why check it. Just check from the start
// By doing this, we do very less iterations
// TC: O(N) asymptotically

