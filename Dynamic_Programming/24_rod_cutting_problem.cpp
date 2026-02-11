// given a particular N
// say n =5
// given a price array say 2 5 7 8 10
// you have to cut the rod into pieces. 
// for each length, there is a price. length 1 has price 2, length 2 has price 5 and so on
// the 5 cm rod can be cut in many ways
// like 1cm 2cm 2cm -> total price 2+5+5 = 12
// similarly 1cm 4cm -> 2 + 8 = 10
// tell what is the max price

// we have a lot of combinations of length
// rod lengths can be 1 2 3 4 5
// collect rod lengths to make the sum N, here 5
// while collecting rod lengths, maximize price
// so instead of breaking the rod, we collect the rods to make a rod of length 5
// so this is now similar to knapsack problem if we make maxweight as 5, and wts of each length be the length itself, and price be their value
// wt = 1 2 3 4 5
// value =  2 5 7 8 10
// max weight = 5
// simple

// try to pick lengths and sum them up to make the max weight
// this is nothing but the knapsack but that we can repeat lengths here, so kind of unbounded knapsack



