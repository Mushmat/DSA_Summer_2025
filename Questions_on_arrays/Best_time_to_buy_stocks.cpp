// Given an array of integers
// If you sell or buy a stock on any given day, (index = day), price of that stock is the element at that index
// Therefore have n number of days
// Decide a day when to buy the stock, and a day when to sell the stock
// Such that maximum profit is guaranteed
// Buy before you sell
// If you sell on ith day, you buy on the minimum price from the first day to the i-1th day.
// Therefore you can check for everyday, the profit if you sell on that day
// for every guy, track the minimal on the left
// mini = a[0]
// profit = 0;
/* for(i = 1; i < n; i++){
        cost = a[i] - mini;
        profit = max(profit,cost);
        mini = min(mini, a[i]);
    }
    return profit;
*/