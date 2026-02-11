// given two strings s1 and s2
// three different operations: 
// 1) insert any character in s1
// 2) delete any character from s1
// 3) replace any character from s1 with any character

// what is the minimum number of steps to convert string s1 to string s2
// in lecture 29, we only were able to do function 1 and function 2
// here we can replace as well
// we have already seen that such transformation is always possible
// say string 1 is horse, string 2 is ros

// replace h with r -> rorse
// remove middle r -> rose
// remove e -> ros
// so we did 3 operations
// this is the minimum

// we have to do string matching, character by character
// if they match, good
// if they dont match, we have many options
// maybe u can insert the same character
// else you can delete and find something else
// else you can replace and match

// how to write the recursion here
// f(i,j) -> minimum operations to convert string s1 [0...i] to string s2 [0...j]
// if(s1[i] == s2[j]) they match so dont perform any operation, so shrink the strings -> return 0 + f(i-1, j-1) // no steps done and shrinked strings
// if they do not match then
// we can do insert, or replace, or delete
// if we insert, i remains same, j moves j-1 as j gets matched to whatever we insert at i+1, so-> f(i, j-1) + 1 // we took 1 step
// if we delete, i goes to i-1 as i is deleted, and j remains the same, so f(i-1, j) + 1 // we took 1 step again
// if we replace, we will replace ith character with the character that is on jth place
// we will replace such that both characters are same, so we will move both i and j backward, because ith and jth now match -> 1 + f(i-1, j-1) // again we took 1 step
// then take minimum

// base cases:
// if s1 gets exhausted or if s2 gets exhausted
// if i < 0, and j remains, that means j still needs to be matched but there is nothing in i. so that means, we need to INSERT j characters to match, because i is empty so we need to add in it
// so if i < 0; we need j+1 operations to make string [0..j]
// if s2 gets exhausted, j < 0, this means that we have got string s2, so we need to delete everything remaining in i, which means i+1 operations

// now optimize

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] ==s2[j]) return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    return dp[i][j] = 1 + min(f(i-1, j, s1, s2, dp), min(f(i,j-1, s1, s2, dp), f(i-1,j-1, s1, s2, dp)));
}

int editDistance(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n-1, m-1, str1, str2, dp);
}

// tabulation below

// again we can use 1-based indexing for tabulation
// everything shifts one ahead, comparisons compare -1

int editDistance(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <=n; j++){
            if(s1[i-1] ==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }

    return dp[n][m];
}