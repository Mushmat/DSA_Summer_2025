// given 2 strings, we know how to print the length of the longest common subsequence
// herw we need to print the longest common subsequence

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

// above is the tabulation submission that we did in the last class

// if we simply print the dp array as

for(int i = 0; i <+ n; i++){
    for(int j = 0; j <=m; j++){
        cout << dp[i][j] << endl;
    }
}

// we will observe that the dp array will get printed in which i has row numbers, j has columns
// at each ith row jth column, dp[i][j] is stored which tells lcs till 0 to i in first string, and 0 to j in second string
// do backward recursion
// start with i = n, j = m
// while (i > 0 && j > 0)
// check if those strings are equal, if(s1[i-1] == s2[j-1])
// if they are equal, take it and move to i-1 j-1 
// else move towards whichever is greater amongst i-1,j and i,j-1

int index = len-1
int i = n, j = m;
while(i > 0 && j > 0){
    if(s[i-1] == t[j-1]){
        ans[index] = s[i-1];
        index--;
        i--, j--;
    }
    else if(dp[i-1][j] > dp[i][j-1]){
        i--;
    }
    else j--;
}