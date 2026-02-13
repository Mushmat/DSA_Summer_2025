// DP ON STOCKS STARTING HERE
// There are six problem of DP ON STOCKS
// This is the first problem
// Space Optimization is important for DP ON STOCKS, it is asked in interviews

// Best time to buy and sell stock - 1
// given an array, if you sell or buy on any given day, the price of that stock on that day is the element in that array on that index
// for n number of days n, we need to tell when to buy and when to sell, for max profit
// we need to maximise profit.
// in order to sell the stock, we must buy it first. so buy will happen before sell
// you can only buy and sell once

// look at this problem with this view:
// if you sell the stock on nth day, then you would have bought it when the price was minimum betweeen 1 to n-1th day
// similarly if you sell at n-1th day, buy it when price minimum in 1 to n-2th days
// so we can try for every day, except buying and selling on 1st day itself
// so we can keep profit as 0 initially, and minimum as a[0]


// for i from 1 to n, 
// cost = a[i] - mini
// profit = max(profit, cost)
// mini = min(mini, a[i]);
// This loop simply gives the max profit

