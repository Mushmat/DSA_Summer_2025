// given an array of positive integers
// tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number

// in previous problems we answered the question DOES THERE EXIST
// here we need to COUNT the number of subsets

// whenever there is a problem related to count, then write the function and in the base case:
// if condition is satisified return 1, else return 0

// f(n-1, S) tells the number of subsets that give sum S till the n-1th index
// if we are at the 0th index, we need to write to cases where we return 1 or return 0
// one case if of the not pick, in which we do not pick that index and go one less index with the same sum
// not pick = f(ind -1, S);
// we can pick an element when the element is small or equal to the sum we are looking for. if sum is 3 and element is 6 then why would we need to pick the element
// so if a[ind] <= s, we pick 
// and when picked, we subtract that index
// pick = 0; if(a[ind] <= s) pick = f(ind - 1, S - a[ind]);
// and then simply add not pick and pick
// return pick + not pick
// now if we are at ind 0, and we have sum S left. then we return 1 if a[0] == sum because we need to return it
// else we return 0 because then the sum is not reachable

// if the sum = 0, then no matter what a[0] is, because then we will NOT PICK a[0] and it will be counted
// so if anytime sum == 0, return 1 is another base case

// this is similar to DP 14, but here we just count both pick and not pick

// Now we can do memoization, tabulation, space opti

// TABULATION SOLUTION

int findWays(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar + 1, 0));

    for(int i = 0; i < n; i++){
        dp[i][0]= 1;
    }
    if(a[0] <= tar) dp[0][num[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= tar; sum++){
            int notTake = f[ind-1][sum];
            int take = 0;
            if(num[ind] <= sum) take = f[ind-1][sum-num[ind]];
            dp[ind][sum] = notTake + take;
        }
    }

    return dp[n-1][tar];


}