// given an array of n integers
// return the max sum of the subsequence with the constraint that no two elements are adjacent in the given arrayList
// eg in an array of 1 2 4, you cant pick 1 2 or 2 4. however u can pick 1 4 to get max sum as 5

// first thought would be to try out all subsequences with the given constraint,
// and then pick the one with the maximum sum
// how to print all subsequences? refer to recursion print all subsequences

// since we are picking elements from the array, we have indices. 
// so to make dp, we have index

// for any index we can either pick the element or not pick it
// when an index is picked, then recursion to the second previous index (index - 2)
// when an index is not picked, then recursion to the first previous index ( index - 1 )
// this is because we cannot take the adjacent element
// if you reach index == 0, thaat means you havent picked index 1. so since index 1 is not picked, simply pick the index 0 therefore to maximise the sum
// if index goes < 0, simply return 0

// now we need to optimize this using memoization
// is there overlapping subproblems here? 
// yes there are overlapping recursive calls, so its better to store the results in a dp array

// now the time complexity has decreased from 2^n to n. but we have got stack space extra

// MEMOIZED SOLUTION

int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int pick = nums(ind) + f(ind -2, nums, dp);
    int notPick = 0 + f(ind - 1, nums, dp);

    return dp[ind] =  max(pick, notPick);

}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    vector<int> dp(n, -1);
    return f(n-1, nums, dp);
}

// TABULATION METHOD
// declare dp of the same size
// base case is to return dp[ind] for ind 0
// therefore dp[0] = a[0]
// one more base case is for ind < 0
// therefore int neg = 0;
// the loop runs when ind is > 0
// therefore run loop from i from 1 to n
// take case is to take a[ind] and jump to dp[i-2]
// non take is to take 0 and jump to dp[i-1]
// dp[i] is then max of take and nontake

// to take care of edge cases, if (i > 1) then take += dp[i-2], so that when i is 1, it doesnt run into error, otherwise adds what is important


/// NOW SPACE OPTIMIZATION
// in order to compute dp[i] we need dp[i-1] and dp[i-2]
// any i needs previous two values
// as of now they are stored in dp array
// we do not require i-3, i-4, etc..
// we just require last 2
// so we require just the 2 spaces
// therefore store the previous two results in two varibles

// therefore TC is O(n) and SC of O(1)

int maximumNoAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int nontake = 0 + prev;

        curi = max(take, nontake);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}