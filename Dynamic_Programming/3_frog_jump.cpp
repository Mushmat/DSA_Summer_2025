// there is a frog on the first step of an N stairs long staircase.
// the frog wants to reach the Nth stair
// Height[i] is the height of the i+1 th stair. if frog jumps from ith to jth stair, the energy lost in the jump is given by height(i-1) - height(j-1)
// if the frog is on the ith staircase, he can jump to either i+1th staircase, or to i+2th stair
// find the minimum total energy used by the frog to reach from 1st to nth stair

// we need to try all possible ways
// we need path with min energy
// so step 1, we express problem as index
// step 2, do all stuff on that index
// step 3, take minimum of all stuffs

// f(n-1) represents min energy to reach n-1 from 0
f(ind){
    if(ind == 0) return 0; // no energy reqd to go to 0 from 0
    // step 2; do all stuffs
    left = f(ind - 1) + abs(a[ind] - a[ind - 1]) // this absolute returns the energy consumed
    if(ind > 1){
        right = f(ind - 2) + abs(a[ind] - a[ind - 2]) // if taken 2 steps instead of 1
    }

    return min(left, right); // left has ways in which 1 jumps, right has 2 steps. both have all steps, return minimum
    
}

// there are overlapping subproblems here
// say i am on step 5, then i will check for step 4 and step 3. step 4 checks for step 3 and step 2. and so on
// so there are overlapping subproblems
// hence we can do memoization for this
// declare array of size n + 1
// before returning, add the value to array
// whenever an index is called, check if it has been previously computed or not
// return if already computed

// MEMOIZED CODE
int f(int ind, vector<int> &heights, vector<int> &dp){
    if(ind  == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if(ind > 1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);

    return f(n-1, heights, dp);

}

// tabulation: bottom up.
// start from the base case and then go up
// take 0, and fill 1 2 3 4 5 ....
// intiialize the dp array
// look at the base case and write it
dp[0] = 0
// the recursion lines are then executed for i = 1 and above
for(i = 1 to n - 1){
    // write the stuff done with the index
    firststep = dp[ind - 1] + abs(a[ind] - a[ind - 1]);
    if(i > 1)
    secondstep = dp[ind - 2] + abs(a(ind) - a[ind - 2]);
    // and store now
    dp[ind] = min(firststep, secondstep);
}

// TABULATION CODE
int frogJump(int n, vector<int> &heights){

    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int fs = dp[ind - 1] + abs(heights[ind] - heights[ind - 1]);
        int ss = INT_MAX;
        if(i > 1){
            ss = dp[ind - 2] + abs(heights(ind) - heights[ind - 2]);
        }

        dp[i] = min(fs, ss);
    }

    return dp[n-1];
}

// we can do its space optimization also
// because we only need the previous guy and the second previous guy to compute current guy

// SPACE OPTIMIZED CODE

int frogJump(int n, vector<int> &heights){

    int prev = 0;
    int prev2 = 0;
    for(int i = 0; i < n; i++){
        int fs = prev + abs(heights[ind] - heights[ind - 1]);
        int ss = INT_MAX;
        if(i > 1){
            ss = prev2 + abs(heights(ind) - heights[ind - 2]);
        }

        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

// Follow up-> there can be k jumps, u can jump to i + 1, i+2, i +3, so on to i + k.
