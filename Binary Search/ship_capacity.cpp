// find the least capacity to ship packages within D days
// you have one ship and N items 
// each item has certain weight and weights array given
// ship runs once per day
// therefore find the LEAST capacity to ship it within D dayys
// we can again get some range and try out checking which is possible
// taking any capacity which is less than the maximum of all weights, it is not possibke 
// therefore answer must start from the max element (low range)
// and the max it can go to is the sum of the weights (high range)
// therefore the answer will be in between max element and the sum
// simply we can now apply BS
// if a mid is a potential answer, then check on left
// if a mid is not a potential answer, then check right.