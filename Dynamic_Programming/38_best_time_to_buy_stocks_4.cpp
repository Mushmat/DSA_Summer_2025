// given prices array
// we have done 1 transaction, inf transactions, 2 transactions
// now here we can do at most k transactions

// last lecture allowed us atmost 2 transactions
// lets copy the same code
// and just change capacity vector size


int maxProfit(vector<int> &prices, int n, int k){
   vector<vector<int>> after(2, vector<int> (k+1, 0));
   vector<vector<int>> cur(2, vector<int> (k+1, 0));

    // we dont have to write the base cases as already we have initilized everything to 0
    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= k; cap++){
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

    return after[1][k];
}