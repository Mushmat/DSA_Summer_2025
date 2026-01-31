// DP on subsequences
// given an array that has the denomications of coins
// given a target
// what is minimum number of coins required to get to the target
// one coin can be taken infinitely

// try out all combos and take min 

// f(ind, target T) = f(ind, T)
// f(n-1, T) = till n-1, what are the minimum coins to get to the target
// now for each index, earlier we had take or not take
// here we can take one coin infinite many times
// so there are two cases
// one is notTake, in which we add no such coins
// int notTake = 0 + f(ind - 1, T) // 0 coins were taken
// int take = INT_MAX
// then if(coins[ind] <= T) then we can take it, take = 1 + f(ind, T - coins[ind]) // since we can repeat a coin, we stay at the same index
// return min of both

// base cases
// at index = 0, we can only take the coin if it is a mulitple of the target
// otherwise we cannot take that coin
// so if target is divisble by the coin, then return target / denomination, else return not possible (INT MAX)

// OPTIMIZED SOLUTION

int minimumElements(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (target + 1, 0));

    for(int T = 0; T <= target; T++){
        if(T % nums[0] == 0) dp[0][T] = T / nums[0];
        else dp[0][T] = 1e9;
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= target; T++){
            int notTake = 0 + dp[ind - 1][T];
            int take = INT_MAX;
            if(nums[ind] <= T){
                take = 1 + f[ind][T - nums[ind]];
            }
            dp[ind][T] = min(take, notTake);
        }
    }

    int ans = dp[n-1][target];
    if(ans >= 1e9) return -1;
    return ans;
}