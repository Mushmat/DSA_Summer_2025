// given a number N, print all the divisors of the number
// order doesnt matter

// brute:
// run a loop from 1 to N and check if i divides N, if yes put it in the list and at the end, print the list
// TC is O(N) and SC is just to return the answer

// optimal:
// we need to optimize the time complexity
// observe that say N is 36
// divisors of 36 are 1 2 3 4 6 9 12 18 36
// now if 1 is a divisor, observe that 1 is being multiplied by 36 to give 36, so 36 is inherently a divisor
// is 2 is a divisor, 2 x 18 = 36 hence 18 is inherently a divisor
// by this, if we figure out a divisor, we can figure out the other in one step itself
// so we need not loop till 36, we need to loop till 6 for this example. 
// what is 6? square root of 36
// hence, start loop from 1 to square root of N
// if(N % i == 0) add i to array
// and also add, N / i
// edge case: when N is perfect square of i. so, if (n / i != i) then only add to array.

// TC: sqrt(n)