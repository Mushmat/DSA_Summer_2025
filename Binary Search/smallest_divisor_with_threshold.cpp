// find the smallest divisor given a threshold
// given an array of integers, and a threshold t
// find smallest divisor such that when everything in the array is divided by the divisor, and seal of every thing is taken, and then summed up
// the sum must be smaller or equal to the threshold
// eg ig array is 1 2 5 9, and threshold is 6. and you choose divisor to be 4. after dividing everything by 4 and taking seal
// array becomes 1 1 2 3, whose sum is 7 > 6, so 4 not the answer
// again it is very simple
// get the range and solve
// simple