// given an array of n integers
// find if we can partition the given array into two subsets such that the sum of elements in both subsets are equal

// we already did in the last problem, whether the arr has a sum equal to target or not
// here in this problem, we need to divide the array into exactly two subsets such that sum1 = sum2
// if entire array sum is S, then both arrays that we divide into has to have sum S/2
// so sum1 = sum2 = S/2
// so now we have a target
// is S is odd: then division is not possible as an odd sum cannot be divided
// if S is even:
// then we are looking for a subset with a sum of S/2
// if we get one subset with sum S/2, that means the remaining elements are bound to give the remaining sum, that is S/2
// so if we get any subset with target S/2, then the answer is yes that we can have two subsets with equal sum

// therefore given an array, check if we have a subset or subsequence with the target S/2 wiith S being the sum of the array

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

bool canPartition(vector<int> &arr, int n){
    int totSum = 0;
    for(int  i =0; i < n; i++) totSum += arr[i];
    if(totSum % 2) return false;

    int target = totSum / 2;
    if(subsetToK(n, target, arr)){
        return true;
    }
    else return false;
}