// (min) of max / (max) of min pattern problem
// given an array containing coodinates of N stalls
// place 4 cows in such a way that the minimum distance between any of the two cows is the maximum
// tell the minimum distance 
// the minimum distance would always happen between consecutive stalls
// you need to find out the minimum distances between any two cows in every combination
// and then return the one combination when the minimum distnace was max of all

// sort the array
// check whether a distance is possible or not. start by keeping cows atleast 1 distance apart, then 2 then 3 etc
// range is [1 , (max dist - min dist)]
// since we have the range, simply check
// if a mid is not possible, check to its left
// if a mid is possible, check to its right for a better answer
