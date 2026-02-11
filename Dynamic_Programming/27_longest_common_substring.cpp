// here we need longest common substring
// substring is contiguous in order
// IT DOES NOT PERMIT NON CONTIGUOUS string

// in the lcs problem earlier, we wrote
// dp[i][j] = 1 + dp[i-1][j-1] if they matched
// otherwise dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// in this we used to break the consecutiveness of the string to find matching letters
// but here we cannot omit the strings that break consecutiveness

// lets jump to the tabulation solution itself
// say string abcd & abzd
// in comparing substrings we cant carry previous stuff as we need continuity
// so in this question instead of the max line, dp[i][j] = 0, if the 'else' is executed
// after every run, the max value in the dp matrix is the answer

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
    int ans = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}