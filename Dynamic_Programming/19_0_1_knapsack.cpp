// VERY IMPORTANT PROBLEM

// there is a theif who goes to some house to steal items
// there are n items say 3
// each item has a particular weight and a particular value
// thief has a bag that has a capacity (a maximum weight)
// to make the perfect steal, thief needs to maximise value constraint the weight of the bag
// greedy approach is not useful here

// therefore lets apply DP
// express each item as an index, and second the weight of the bag (ind, W)
// explore all possibilities (take or not take)
// max all possibilites

// f(n-1, W) gives till ind n-1, what max value can we get with bag weight W
// f(ind, W)
// notTake = 0 + f(ind-1, W) // didnt pick any item, bag weight remains same
// take = INT_MIN; (if not taking them we take very small value)
// if(ind[wt] <= W) then only we can steal it
// Take = ind.value + f(ind - 1, W - ind.wt)
// return max of both

// base cases:
// base case is at 0th index
// if(ind == 0)
// if(wt[0] <= W) return val[0] // we can steal the item
// else return 0 // we cannot steal the item

// now this can be memoized and tabulized, then space optimized

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int> (maxWeight + 1, 0));
    for(int W = wt[0]; W <= maxWeight; W++) dp[0][W] = val[0];

    for(int ind = 1; ind < n; ind++){
        for(int W = 0; W <= maxWeight; W++){
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + dp[ind-1][W - wt[ind]];
            }
            dp[ind][W] = max(take, notTake);
        }
    }

    return dp[n-1][W];
}

// this can be space optimized now