// Increasing subsequences problems
// this question wants us to return the longest increasing subsequence
// we do not need to maximize the sum, we just need to maximise the length 
// in this question we just need to print the max length of the increasing subsequence

// in this question also, we will either take or not take

// also, increasing -> strictly increasing

// so lets write recursion
// we need to store the previous element to compare to the current element
// f(ind, prev)
// f( 3, 0 ) means length of LIS starting from third index whose previous index is 0 [ previous index -> the starting index of the array]

// f(ind, prev_ind)
// if we do not take, then 0 + f(ind+1, prev_ind), previous index stays the same if we do not take, as this element is not included in the subsequence
// if we take, then, 
// index increases to the next index, and the previous index becomes this index. 
// we can take it if it is the first element that is, prev == -1 or if it is bigger, arr[ind] > arr[prev_ind]
// if we take then, 1 + f(ind+1, ind)
// then take max of both take and not take

// base cases
// when we run out of indices, at n
// if (ind == n) return 0;
// also, we will do a coordinate shift in prev_ind array to accomodate prev_ind = -1
// every index is shifted by 1


inf f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
    int len = 0 + f(ind+1, prev_ind, arr, n, dp);
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        len = max(len, 1+f(ind+1, ind, arr, n, dp));
    }
    return dp[ind][prev_ind+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return f(0,-1,arr,n, dp);
}

// here we need to convert the previous code to the tabulation code
// in tabulation code, ind will go from n-1 to 0
// and prev_ind goes from ind-1 to 0

int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int ind = n-1; ind >= 0; ind--){
        for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
            int len = 0 + dp[ind+1][prev_ind+1];
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                len = max(len, 1 + dp[ind+1][ind+1]);
            }
            dp[ind][prev_ind+1] = len;
        }
    }
    return dp[0][0];
}

// in the above code we have done the LIS tabulation code, which can be space optimized further
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> next (n+1, 0), cur(n+1, 0);
    for(int ind = n-1; ind >= 0; ind--){
        for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
            int len = 0 + next[prev_ind+1];
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                len = max(len, 1 + next[ind+1]);
            }
            cur[prev_ind+1] = len;
        }
        next = cur;
    }
    return next[0];
}


