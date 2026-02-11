// what is the minimum no of insertions to make a string palindrome
// we can insert any character anywhere
// one hack is to see that we can simply reverse the string and concatenate it with the original string and it will be a palindrome
// but here we need minimum insertions
// say string a is abcaa, we can reverse it and write abcaa aacba which is a palindrome. so max insertions is 5
// but how to get minimum???

// maybe we can write aabcbaa (add a before b and b after c)
// so two insertions and it is a palindrome
// so how to approach the question

// first, keep the palindromic portion intact
// in string abcaa, aa is a palindrome protion, a is a palindrome, aaa is a palindrome, aba is a palindrome and so on
// keep the LONGEST palindromic portion intact
// say we take aaa (longest palindromic subsequence)
//so now we have that a a a
// two guys b and c do not have a match
// we can make a match by, taking bc and putting it after the centered a: as in, 
// a bc a bc a
// but this isnt a palindrome, so reverse that bc after the center
// a bc a cb a
// now it is a palindrome
// so we kept the longest palindrome intact and reversed the not palidnromic sequences and put it after the center character

// so our answer that is minimum no of insertions, is essentially n (the length of the string) - length of longest palindromic subsequence
