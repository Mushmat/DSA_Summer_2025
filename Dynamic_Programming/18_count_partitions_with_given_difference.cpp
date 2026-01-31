// given an array, partition it into two subsets (possibly empty) such that their union is the origina; array.
// let the sum of the elements of these two subsets be S1 and S2
// given a difference D, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to D

// so given an array, divide it into two parts st s1 >= s2 and s1 - s2 = D
// s1 can be written as total sum - s2
// thenn, total sum - s2 - s2 = D
// total sum - D = 2 x S2
// therefore s2 = total sum - D /2
// therefore we need subsets which have this S2
// therefore the question is now to find the count of subsets whose sum is K
// which is done in DP 17

// return false if total sum - D < 0 or totalsum - D is odd
