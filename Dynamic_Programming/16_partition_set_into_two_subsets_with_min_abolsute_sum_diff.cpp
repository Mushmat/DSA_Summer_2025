// you are given an array containing N non negative integers.
// task if to parititon into two subsets such that the absolute difference between subset sums is minimum
// find the minimum diff and return

// the absolute differemce of the sums have to be minimum

// we know how to check whether there exists a subset whose sum is equal to a target or not
// we can tell YES or NO for every target value from 1 to the target value given to us
// therefore from subset sum, we have derived that if we check for a target = k, we can derive that 
// if every possible target between 1 & k, is possible or not

// we need abs(s1 - s2) to be minimum
// if we can figure out s1, we are good to go
// because if we know the total sum and s1, then we already know s2 as total - s1
// if we have all the possible S1, then we can try out all partitions of S1
// the minimal summtion of S1 is 0 where we do not pick any element, and the max summation is total sum when we say we pick all the elements
// so we have a range from 0 to 12
// we can call tabulation method of lecture 14 to the target 12. then the last row of the tabulation gives which all targets are possible
// check which sums are possible in 0 to 12
// those are the valid partitions for which we can then find corresponding S2
// and simply find minimal and return


int minSubsetSumDifference(vector<int> &arr, int n){

    int totSum = 0;
    for(int i = 0; i < n; i++) totSum += arr[i];

    int k = totSum;
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    for(int i = 0; i < n ; i++) dp[i][0] = true;

    if(arr[0] <= target) dp[0][arr[0]] = true;

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

    // dp[n-1][col -> 0....totSum]
    int mini = 1e9;
    for(int s1 = 0; s1 <= totSum / 2; s1++){
        if(dp[n-1][s1] == true){
            mini = min(mini, abs((totSum - s1) - s1));
        }
    }

    return mini;
}
