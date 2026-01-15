// we know that for fibonaaci numbers, 
// f(n) = f(n-1) + f(n-2)
// in dp, whenever we solve a subproblem, store it in a database so that in future that problem is not solved again, to save time

// MEMOIZATION IS USED HERE SIMPLY TO CONVERT RECURSION TO DP
int f(int n, vector<int> &dp){

    if(n <=1 ) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1) + f(n-2);

}
int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1,-1);
    cout << f(n, dp);

}

// Time complexity: the deeper recursion calls are n, once those are done, other calls are in constant time as we have got their answer already
// therefore TC = O(n)
// Space: Recursion stack space: O(N) + Array Space O(N)

// if we use the tabulation method instead of memoization, we run a loop from i from 2 to n, and do dp[i] = dp[i-1] + dp[i-2]. since we already have dp[0] = 0, dp[1] = 1
// this way we start from base case and move to the answer
// here space complexity does not include recursion stack space, so better SC

// SPACE OPTIMIZATION:
// instead of storing an array, we can simply store two variables prev and prev2 to give the answer
// this will eliminate the array space as well

// below is the space optimized code
int n;
cin >> n;
int prev2 = 0;
int prev = 1;
for(int i = 2; i < n; i++){
    int curi = prev + prev2;
    prev2 = prev;
    prev = curi;
}

cout << prev;