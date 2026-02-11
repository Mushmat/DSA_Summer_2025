// given a string say bbbab
// we need length of the longest palindromic subsequence
// bbbb here

// the optimized way to do this is:
// we have already learnt LCS
// if we want to map this question to LCS
// we can observe that in a palindrome, the strings match left and right
// if s1 is the string we need to find longest palindrom from
// write s1 in reverse order
// and then find longest common subsequence in these two strings
// that subsquence will be the longest palindrome
// simpleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee