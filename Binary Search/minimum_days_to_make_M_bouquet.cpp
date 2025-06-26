// given an array bloomDays
// consisting of blooming days for n flowers 
// eg if array is 7 7 7 7 13 11 12 7
// means the first flower will bloom on 7th day and so on
// return minimum number of days required such that you have ample amount of blooming flowers to make m bouquets and should have taken k adjacent flowers to make one bouquet
// if not possible, return -1
// to apply BS, we need a range
// minimum answer can be the minimum days any flower takes to bloom
// maximum answer can be the maximum days any flower takes to bloom
// got the range
// make a function to check whether it is possible or not on a particular day (f(arr, day, m, k))
// apply BS now