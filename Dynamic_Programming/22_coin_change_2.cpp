// given array with denominations
// form the target
// any element can be used any no of times
// count the total number of ways to make the target

// f(ind-1, target) gives till index ind-1, how many ways can form target
// f(ind, T)
// again, either take or not take
// notTake = f(ind-1, T)
// when we take, write the if condition when we can take, and take it
// take = 0;
// if(arr[ind] <= T) take = f(ind, T - a[ind]);
// return take + not take
// base case:
// at index 0,
// again, if the target is divisible by the coin, we can take it

// OPTIMIZED SOLUTION

long countWaysToMakeChange(int *denomincations, int n, int value){
    vector<vector<long>> dp(n, vector<long> (value + 1, 0));
    for(int T = 0; T <= value; T++){
        dp[0][T] = (T % a[0] == 0);
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T<=value; T++){
            long notTake = dp[ind-1][T];
            long take = 0;
            if(a[ind] <= T) take = dp[ind][T-a[ind]];
            dp[ind][T] = take + notTake;
        }
    }

    return dp[n-1][value];
}