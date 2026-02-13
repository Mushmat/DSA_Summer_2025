// given prices array
// here cooldown is given
// cooldown means, you cant buy right after you have sold
// basically if u sold on nth day, you cannot buy on n+1th day
// we can buy n sell for inf time

// what we can do is
// whenever we sell, do not go to ind+1, go to ind+2
// because ind+1 you cannot buy
// simple