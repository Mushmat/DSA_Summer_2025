// given an array of integers
// a subset can have numbers in any order
// a divisble subset is a subset, in which any two elements divide each other
// either i can divide j or j can divide i
// for eg in an array 1 16 7 8 4, the longest divisible subset would be 1 16 8 4
// array will have distinct numbers
// we can print any order of the subsets

// how to relate this with LIS
// since we can print any answer, let us sort the array
// so we start picking 1, then pick 4 since 4 is divisible by 1, then pick 8 since it is divisible by 4 which indirectly means it is divisible by 1 also
// similarly we pick 16 which is divisible by 8, hence divisible by everyone else
// so whenever we pick an element, since array is sorted, if element is divisible by previous one, it is divisible by all
// so basically we are looking for longest divisble subsequence
// so instead of longest increasing, check for longest divisible

