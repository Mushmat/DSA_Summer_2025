// DP ON SUBSEQUENCES (aka SUBSETS)

// subsequence: contagious or non contagious part of the array in order
// given a target

// you are given a arrat ARR of n positive integers and an integer K. 
// task is to check if there exists a subset in ARR with a sum equal to k

// return true if there exists a subset with sum K else return false

// first thought is to generate all the subsequences and check if the sum is k or not
// but here we do not need to generate all the subsequences. we just need to keep a check whether any subset sums to K
// therefore we can do recursion and check

// -> again express everything as an index, and keep a target
// -> do all stuffs (explore possibilities of that index) if(a[ind] is in the subsequences or not)
// -> return equals (true or false)

// f(n-1, target): In the entire array till the index n-1, does there exist any target?
// what are the base cases here?
// if(target == 0) return true; as we have got the target
// if(ind == 0) return(a[0] == target); if we have reached 0th index, the value at 0th index needs to be the target left
// now we need to explore possibilites of that index
// bool not take = f(ind - 1, target); we did not take the ind'th index
// bool take = false; initially
// if(target >= a[ind]) // we can only take the element when target is greater or equal
// take = f(ind-1, target - a[ind]);
// after doing this, if there is a possibility
// return take OR not take // if any of these return true, we return true

// there will be overlapping subproblems so we can apply memoization
// if we can apply memoization, we can apply tabulation

// in tabulation; number of states = number of loops (here two states: ind and target, so two loops)

// MEMOIZED SOLUTION

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (a[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = f(ind - 1, target, arr, dp);
    bool take = false;
    if(a[ind] <= target){
        take = f(ind - 1, target - a[ind], arr, dp);
    }
    
    return dp[ind][target] = take | notTake;
}   

bool subsetToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return f(n-1, k, arr, dp);
}

// TABULATION
bool subsetToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    for(int i = 0; i < n ; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int ind  = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(a[ind] <= target){
                take = dp[ind-1][target - a[ind]];
            }
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n-1][k];
}
