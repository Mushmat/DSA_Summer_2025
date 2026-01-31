// here, again there is a thief
// bag weight is 10
// items have wt and value
// unbounded knapsack tells that the thief can steal an item infinite many items
// so there is infinite supply of an item. 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int> (maxWeight + 1, 0));
    for(int W = wt[0]; W <= maxWeight; W++) dp[0][W] = (W / weight[0]) * val[0]; // base case changes as we can pick multiple

    for(int ind = 1; ind < n; ind++){
        for(int W = 0; W <= maxWeight; W++){
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + dp[ind][W - wt[ind]]; // stay at the same index
            }
            dp[ind][W] = max(take, notTake);
        }
    }

    return dp[n-1][W];
}