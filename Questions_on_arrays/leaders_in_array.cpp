// Given an array, find the leaders
// Leaders are those elements where all the right elements are smaller
// Eg in 10 22 12 3 0 6, leaders are 22 12 6
// Brute:
// Pick one element and check on the right for an element greater than the picked one
// If you find an element greater than the picked one, then that is not the leader
// Do this for every single element
// TC: O(n^2)

// Optimal:
// For an element, check the maximum element to its right, if that max element is smaller than the current element, then bv the current element is the leader
// therefore check whether the picked element is greater than the maximum on the right
// start iterating from the back, keep max as INT_MIN
// On the right of the last element, the max is INT_MIN, so the rightmost element is leader, store it
// Store max now as the rightmost element and iterate left
// If the element is greater than max, it is a leader, if not. move left
// Repeat till exhaust
