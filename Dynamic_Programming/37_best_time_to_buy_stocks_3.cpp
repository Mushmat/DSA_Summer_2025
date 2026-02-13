// given prices array
// here we are allowed to do at max 2 transactions
// not more than 2 transactions
// in the last question, we could do multiple transactions, but here only 2 are possible

// so here we will do like:
// f(ind, buy, cap) where cap is the capacity which cant be exceeded, initially cap = 2
// cap is only decreased when a transaction is COMPLETED
// lets write cases now
// if(buy)
// then, if we DO BUY, then -prices[ind] + f(ind+1, 0, cap) // since transaction not completed, return cap
// if we DO NOT BUY then, 0 + f(ind+1, 1, cap)
// return max of both

// else() // we cannot buy, means we need to sell
// if we do SELL, then prices[ind] + f(ind+1, 1, cap - 1) as one complete transaction has been completed
// if we do NOT SELL, then 0 + f(ind+1, 0, cap)
// return max of both

// simple
// base cases:
// again if ind == n, return 0
// but also, if cap == 0 return 0

// now optimize

// here there are three changing parameters, so a dp of three will be used

// below is tabulized solution followed by space optimized solution

int maxProfit(vector<int> &prices, int n){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

    // we dont have to write the base cases as already we have initilized everything to 0
    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if(buy == 1){
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap], 0 + dp[ind+1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}

// space optimized

int maxProfit(vector<int> &prices, int n){
   vector<vector<int>> after(2, vector<int> (3, 0));
   vector<vector<int>> cur(2, vector<int> (3, 0));

    // we dont have to write the base cases as already we have initilized everything to 0
    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if(buy == 1){
                    cur[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                }
                else{
                    cur[buy][cap] = max(prices[ind] + after[1][cap], 0 + after[0][cap]);
                }
            }
        }
        after = cur;
    }

    return after[1][2];
}
