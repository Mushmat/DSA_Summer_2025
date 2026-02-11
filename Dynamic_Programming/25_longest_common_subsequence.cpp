// THIS IS THE FIRST PROBLEM OF THE PATTERN DP ON STRINGS
// GENERAL PROBLEMS: COMPARISONS, REPLACEMENTS AND EDITS, ETC

// THIS PROBLEM:
// subsequence again: contiguous or non contigous sequence in order

// for a string of length n, number of sequences is 2^n
// this problem here, wants us to return longest common subsequence in two strings

// brute force is exponential, where we generate all subsequences and compare them

// we will write some recurrence which gives the answer through the way itself
// keep two indices, one to represent string 1, other to represent string 2
// f(2,2) -> what is the longest common subsequence in first string from 0 to 2 index, and in second strig from 0 to 2 index
// f(ind1, ind2)
// do comparisons character wise
// if two characters match, we get answer as 1 and then move the index pointer ahead to compare next characters
// eg in acd / ced, d matches. so when at d, we do 1 + f(1,1) because d has matched, and next character is to be compared
// so
// if(s1[ind1] == s2[ind2]) then 1 + f(ind1-1, ind2 - 1);
// if characters do not match then?
// say ec/ce
// pointer 1 is at c, pointer 2 is at e
// so since they do not match, keep pointer 1 at the place, and move pointer 2
// and secondly, pointer 1 is moved, pointer 2 is at the place
// so when the characters do not match, move the pointers one by one
// if not match then
// 0 + max(f(ind1 - 1, ind2),f(ind1, ind2 - 1))

// what is the base case
// when does the base case come?
// it comes when any one of the indices become negative
// negative inherently means End of the string
// if(ind1 < 0 || ind2 < 0) return 0; 

// now we will do memoization, tabulation, and space optimization to this

// Recursive TC is 2^n x 2^m, which is very costly
// So this can be memoized for optimization

// make an N x M dp for memoization
#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);

    return dp[i][j] = max(f(i-1,j,s,t, dp), f(i, j-1, s, t, dp));
}

int lcs(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n-1, m-1, s,t, dp);
}

// THIS TIME COMPLEXITY IS N X M

// Below is the tabulation code optimized for space

int lcs(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    // since we cannot write base casses as dp[-1] here, we do shifting of index
    // f(0) will mean -1, f(n) means n-1 and so on
    // therefore every i must be treated as i-1, and every j as j-1
    // so base case will be if(i == 0 (signifies i = -1) || j == 0) return 0

    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}