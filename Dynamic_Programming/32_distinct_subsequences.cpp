// distinct subsequences
// given two strings, say babgbag & bag
// we need to tell how many times string 2 appear in string 1
// here, bag occurs 5 times in string 1

// we need to apply recursion here
// count the number of ways
// so again
// base case: either count 1 or count 0
// how to write the recurrence?

// parameter i -> represents index in string 1
// parameter j -> represents index in string 2
// explore all possibilties
// return summation of all possibilities
// and write the base case

// f(n-1, m-1) means number of distinct subsequences of string s2[0...j] in string s1[0...i] ( n - 1 <= i, m - 1 <= j)
// f(i,j)
// if(s1[i] == s2[j]) (if they match) 
// one case is to keep the match and move both pointers back, other case is when we want another character to match
// f(i-1, j-1) or f(i-1, j) // we matched g with g and bag became ba, secondly, we didnt match and bag remain bag
// if characters doesnt match, then there is only one option to go back in i
// if(s1[i] != s2[j]) f(i-1, j)
// return sum

// what is the base case
// base case has to return 1 or 0
// when does the base case return 0 or 1?
// if i < 0 and j still looks for some character, then we couldnt find the matching
// if j < 0, means we matched everything, so we can return 1
// so if(j < 0) return 1
// if(i < 0) return 0; 

// now we will optimize

int f(int i, int j, string s, string t, vector<vector<int>> &dp){
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = f(i-1,j-1, s, t, dp) + f(i-1,j, s, t, dp);
    }
    
    return dp[i][j] = f(i-1, j, s, t);
}

int numDistinct(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int> dp(m,-1));
    return f(n-1, m-1, s, t, dp);
}

// TABULIZED CODE BELOW
// using 1 based indexing, changing the index (as in PRINT LCS LECTURE)
// move the index ahead by 1
// n-1,m-1 becomes n,m
// and the base cases become if j = 0 return 1, if i = 0 return 0
// match as s1[i-1] == s2[j-1]
// everything else remain same

itn numDistinct(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= m; j++) dp[0][j] = 0; // j started from 1 as for j = 0, we did already write 1

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
            dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}