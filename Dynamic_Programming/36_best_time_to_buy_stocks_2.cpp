// DP on stonks second problem

// given prices array on each day
// again we need to buy and sell
// here, we can buy as many times, and sell as many times
// so we can buy on day 2, sell on day 3, buy on day 4, sell on day 6 and so on
// we must sell once we have bought once. basically if we buy, we must sell before buying again
// give the maximum profit

// here we will use recursion and try all ways of buying and selling
// 1) express everything in terms of index -> here we have 1d array -> so (ind, ... )
// on any index we need to know whether we have previously bought or sold things, so that we know what we can do at that index
// so second parameter we need to take is a variable 'buy' which tells can i buy or not
// if i CAN buy, then its on me to buy or not buy. if i CANT buy, then i can sell or not sell
// 2) explore possibilities on that day
// 3) take the max of all profits made

// f(ind, buy) ->  start at 0th index
// at f(0,) we can buy, so buy is 1. so f(0,1) [ 1 means we can buy, 0 means we cant buy]
// which signifies, starting on the 0th day what maximum profit i can get

// f(ind, buy)
// there are two possibilities, either we can buy or we cant, for both cases i can make two profits
// if(buy)
// we might buy or might not
// which is essentially take or not take
// whenever we buy, we add negative of the price, and when we sell, we add positive of the price, to our answer
// so if we buy, profit = -prices[ind] + f(ind+1, 0) // now buy = 0
// else if we dont buy then profit = 0 + f(ind+1, 1)
// profit at this point will be max of the above
// if buy is not true, then we can either sell or not sell
// if we sell then, profit = prices[ind] + f(ind+1, 1) // since we sold, buy = 1
// if we dont sell, profit = 0 + f(ind+1, 0)
// again take max

// base case comes when we exhuast all dates (ind == n)
// at which point, we need to think
// if we bought a stock and did not sell, which means buy = 0, that means we have no profit, so we can return 0, as no profit
// so if ind == n, return 0

// now we can optimize this for memoization, tabulation and space optimization

int f(int ind, int buy, long *values, int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    int profit = 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy){
        profit = max(-values[ind] + f(ind+1, 0, values, n, dp), 0 + f(ind+1, 1, values, n, dp));
    }       
    else{
        profit = max(values[ind] + f(ind+1, 1, values, n , dp), 0 + f(ind+1, 0, values, n , dp));
    }
    return dp[ind][buy] = profit;
}



long getMaximumProfit(long *values, int n){
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return f(0, 1, values, n, dp);

}

// below is the tabulized code
// 1) base case
// 2) write changing parameters i and buy
// 3) copy the recurrence

// base case is?
// ind == n
// create dp[n+1][2]
// start with dp[n][0] = dp[n][1] = 0

// then, i will go from n-1 to 0 (REVERSE OF MEMOIZATION)
// buy will also go from 0 to 1
// copy recurrence

long getMaximumProfit(long *values, int n){
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy){
                profit = max(-values[ind] + dp[ind+1, 0], 0 + dp[ind+1, 1]);
            }       
            else{
                profit = max(values[ind] + dp[ind+1, 1], 0 + dp[ind+1, 0]);
            }
            dp[ind][buy] = profit;
        }
    }

    return dp[0][1];
}

// now we need to space optimize it
// observe that we are dependent on the previous guy, ind+1


long getMaximumProfit(long *values, int n){
    vector<long> ahead(2, 0), cur(2, 0);

    ahead[0] = ahead[1] = 0;
    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy){
                profit = max(-values[ind] + ahead[0], 0 + ahead[1]);
            }       
            else{
                profit = max(values[ind] + ahead[1], 0 + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }

    return ahead[1];
}

// THIS IS THE MOST OPTIMIZED SOLUTION