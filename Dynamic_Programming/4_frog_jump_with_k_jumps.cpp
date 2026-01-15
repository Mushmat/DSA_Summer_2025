// follow up question from frog jump (2 jumps)
// what if frog can jump k jumps

//for all jumps, we can just compute for all k jumps, and return the minimum
// using a for loop

f(ind){
    if(ind == 0) return 0;
    minSteps = INT_MAX;
    for(j = 1 to k){
        if(ind - j >= 0) {
            jump = f(ind - j) + abs(a[ind] - a[ind - j]);
            minSteps = min(minSteps, jump);
        }
    }

    return minSteps;
}

// if we apply memoization to it, we can add the dp[n] array
// observe that every junction takes k steps.
// if there are n states and k jumps, then TC is O(N x K)
// SC: O(n) + O(n)