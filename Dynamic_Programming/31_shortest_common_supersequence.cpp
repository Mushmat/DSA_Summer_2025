// shortest common supersequence
// supersequence: both strings are there
// say string 1 is brute, string 2 is groot
// then brutegroot is a supersequence but is not the shortest
// bgruoote is the shortest supersequence, it has brute n groot both
// the order must be preserved

// start from start of both the strings
// if both are unequal, take both in order
// if both are equal, take any of them
// so basically we arent taking common things

// so, common guys taken once
// which is LCS
// here, in brute and groot, rt is the LCS
// we need to take everything apart from LCS
// so from brute take bue
// from groot, take goo
// and take LCS once
// which is rt
// answer will be then? n + m - lcs
// because we took lcs twice
// so we have got the length of shortest supersequence

// how to figure out the string now
// remember lecture of print lcs
// we said if two strings match, dp goes to 1 + dp[i-1][j-1];
// else we checked max of both i-1,j and i,j-1
// in here, 

// when two characters dont match, add the not matching character and move back as we did in PRINT LCS LECTURE
// when a character matches, take only once and move backward
// reverse the answer at the end
// so it is just about moving back and taking characters

// just rememebr, when we move up, insert ith guy to the ans
// when we move left, take jth guy to the answer
// whenever any index becomes 0, take all the elements of other string

int shortestSupersequence(string s, string t){
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
    
    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += s[i-1];
            i--;
        }
        else{
            ans += t[j-1];
            j--;
        }
    }

    while(i > 0){
        ans += s[i-1];
        i--;
    }

    while(j > 0){
        ans += t[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}