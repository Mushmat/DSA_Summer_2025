// Lower Bound = smallest index such that arr[index] >= x
// eg for an array = 3 5 8 15 19
// if x is 8, then the lower bound is 2 (index 2)
// if x is 9, then the lower bound is 3 (index 3)
// if x is 16, then the lower bound is 4 (index 4)
// if x is 20, then the lower bound does not exist and can be said as the size of the array (index 5) hypothetically
// to find lower bound:
// keep an ans = the size of array (assume)
// find mid
// if the element at mid >= x, it can be a lower bound but there can be elements to the left of it even smaller
// therefore store that index as the ans and make high = mid - 1, so that we can look further
// again look for a valid answer and keep looking till we exhaust the cases (low > high)

// Upper Bound = smallest index such that arr[index] > x (not equal)
// Run Binary search just change conditions
