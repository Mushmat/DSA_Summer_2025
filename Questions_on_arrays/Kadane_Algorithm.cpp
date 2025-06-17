// Maximum Subarray Sum
// Out of all the subarrays, give the maximum sum subarray (contiguous)
// Brute:
// Try out all subarrays
// Return the one with max sum
// O(n^3)

// Optimal:
// Kadane's Algorithm
// maximum = lowest number (INT_MIN)
// Start from 0th index, and take sum = 0
// Iterate through the array, add the element to the sum
// compare the sum with maximum, if sum > maximum, maximum = sum
// at any moment when sum < 0, no need to take it
// make sum = 0 if sum < 0
// again move to next element, add it to the sum. check for maximum, and now if sum < 0, do sum = 0
// Once iteration finishes, return the maximum

/*
    long long maxSubarraySum(int arr[], int n){
        long long sum = 0, maxI = LONG_MIN;
        for(int i = 0; i < n; i++){
            sum += arr[i]
            
            if(sum > maxI) sum = maxI;

            if(sum < 0) sum = 0;
        }
    }
*/