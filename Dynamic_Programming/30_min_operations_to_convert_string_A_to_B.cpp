// min operations to convert string A to string B or 1 to 2
// we can delete any character from str 1, or insert anywhere in str 1
// return the minimum possible operations

// max operations can be n + m (delete whole string n, add whole string m)

// say string 1 is abcd, and string 2 is anc
// what are the minimum operations?
// delete b d, insert n -> 3 operations

// to minimize, do not touch minimal portions
// do not touch the common portion
// abcd anc
// do not touch a c
// keep a c
// then go from abcd to ac 
// how, delete b d
// then go from ac to anc
// how, insert c
// so what is ac? -> longest common subsequence among s1 s2
// no of deletions = length of s1 - length of lcs
// no of insertions = length of s2 - length of lcs
// and simply ans = deletions + insertions

