// check if a given number N is prime number of not
// a number is prime when the no of divisors are 2
// by this logic, 1 is not a prime

// brute is to loop from 1 to N, and check if i divides N or not

// optimal:
// in last problem we got the divisors of a number
// here as well, we can just check till sqrt(N) and if at the end, cnt == 2, then return YES else NO
