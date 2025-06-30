// given n walls and an array that tells which wall has what units to be painted
// eg if array is 10 20 30 40, first one needs 10 units to be painted, second needs 20 units to be painted and so on
// to paint 1 unit, u take 1 unit of time
// given k painters
// each painter must paint something
// eg if k = 2, one possibility is that one painter paints 10 20, and painter 2 paints 30 40
// many possibilities are there 
// only contiguos allocation is allowed 
// get the time in all possibilities, when both painters finish their job
// return the minimum of these times
// therfore min (all max) is the answer
// this is similar to the book allocation problem
// hence we can take a similar range and solve it