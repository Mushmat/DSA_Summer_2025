// koko wants to eat banannas
// given n piles and every pile has certain number of bananas
// given an hours h
// koko has to eat bananas the fastest
// she can only take at max of h hours
// return minimum integer k such that koko can eat all bananas in h hours
// k is the number of bananas she needs to eat in each hour
// in one hour, only one pile can be accessed
// minimum possible answer can be 1 banana per hour
// what can be the maximum? the maximum number of bananas in a pile is the max number of bananas koko can eat in an hour
// therefore answer always lies between [1, max bananas in all of piles]
// we can easily apply BS to solve this
// find the mid, check if the mid is a possible answer, if yes. then look for a better answer on the left, since all numbers on right are worse answers
// if mid is not a possible answer, eliminate the left half and check for a possible answer on right
// once the best answer is obtained, return