// given prices array
// and a transaction fee
// buy n sell for unlimited time
// everytime you complete a TRANSACTION, a transaction fee will be charged
// so if you buy and sell for 2 times, a 2 x transaction fees is charged

// basically, just buy and sell. count how many complete transactions and charge fees
// so whenever you sell, which means a transaction is completed, there put transaction fees:
// prices[ind] - fee + f(ind+1, 1)