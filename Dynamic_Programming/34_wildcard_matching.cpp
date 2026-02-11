// LAST PROBLEM ON DP ON SUBSEQUENCES
// given two strings
// in those strings, you can have ? or *
// ? means it matches with single character
// * means it matches with sequence of length 0 or more
// say s1 = ?ay and s2 = ray
// y y matches, a a matches, r ?. ? says single character match, so ? matches with r
// so all three characters of s1 match with s2 -> return TRUE
// say s1 = ab*cd
// say s2 = abdefcd
// * means it can match any sequence
// d d, c c match. b match b, a match a. * matches with def
// so here also s1 s2 match -> return TRUE
// but if s1 = **abcd
// and s2 = abcd
// then, these also match. abcd match with abcd. and ** matches with length 0
// RETURN TRUE AGAIN

// if s1 = ab?d and s2 = abcc, then a matches a, b matches b, ? matches c, but d doesnt match c -> RETURN FALSe

// only s1 can have ? *
// s2 will have lowercase letters only

// to match characters with *, we have to try all possible ways -> RECURSION
// return true if any of the ways is true

// f(i,j) -> string1[0...i], string2[0...j], in the string 1, in the string 2, do they match from 0...i and 0...j
// returns yes or no

// f(i,j)
// if they match, either both the characters would match, or their would be a ? in str1 to match
// if(s1[i] == s2[j] || s1[i] == '?') return f(i-1, j-1)
// other condition is when they do not match
// then what
// what if i is at a * and j is at another character
// for *, we can either say that j is empty, and shrink i
// or, we can start matching characters in j with *
// so take the first case of * being nothing
// if(s1[i] == '*') then return f(i-1, j)
// if its not nothing, then we need to check for length 1 2 3 4....
// how can we do this
// by reducing * one by one
// if(s1[i] == '*') then return f(i-1, j) or f(i, j-1)
// what if the string didnt match, it is not *, it is not ?
// then return FALSE

// base cases
// either s1 gets exhausted, or s2 gets exhausted
// i < 0 -> s1 has no more characters left, in order to then match with s2, s2 must also have no characters i.e. j < 0 -> then return true
// otherwise if only i < 0 then return FALSE since s2 is yet to be matched
// now if s2 has exhausted, means j < 0
// then that means s1 still has something
// s1 can match with an empty string s2 if and only if s1 has all *
// then only * can act as empty and match
// if s1 has anything other than *, it cannot match RETURN FALSE
// for(0 to i) if anyone not star, return FALSE, else return TRUE

int f(int i, int j, string pattern, string text){
    if(i < 0 && j < 0) return true;
    if(i < 0 && j >= 0) return false;
    if(j < 0 && i >= 0){
        for(int ii = 0; ii <= i; ii++){
            if(pattern[ii] != *) return false;
        }
        return true;
    }

    if(pattern[i] == text[j] || pattern[i] == '?'){
        return f(i-1, j-1, pattern, text);
    }
    if(pattern[i] == '*'){
        return f(i-1, j, pattern, text) | f(i, j-1, pattern, text);
    }

    return false;
}

bool wildcardMatching(string pattern, string text){
    int n = pattern.size();
    int m = text.size();
    return f(n-1, m-1, pattern, text);
}

// above code can be easily memoized
// lets see tabulized solution
// again use 1-based indexing as we have i < 0

bool wildcardMatching(string pattern, string text){
    int n = pattern.size();
    int m = text.size();

    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

    dp[0][0] = true;
    for(int j = 1; j <=m; j++){
        dp[0][j] == false;
    }

    for(int i = 1; i <= n; i++){
        int fl = true;
        for(int ii = 0; ii <= i; ii++){
            if(pattern[ii] != *){
                fl = false;
                break;
            }
        }
        dp[i][0] = fl;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[i-1] == '*'){
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }

            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}