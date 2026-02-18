// PARTITION DP STARTS HERE
// question types: solve a problem in a particular pattern  
// eg (1 + 2) + (3 * 5) or (1 + 3 + 5) * 8
// given an array, we will have to solve some portion first and other portion after that (there will be partitions)
// generally, start is called i and end is called j

// MCM: Matrix Chain Multiplication
// Say given 3 diff matrices with 3 dimensions
// We need to check whether if two matrices can be multiplied
// How many operations to multiple a nxm with mxt matrix -> n x m x t
// eg for 10x30 and 30x5 matrix, 10 x 30 x 5 is required -> 1500 operations
// these are the number of multiplications we must do to multiply the matrix

// TO multiply three matrices, there can be many ways
// Like (AB)C or A(BC) or (AC)B if all dimensions match 
// which way of multiplying the three matrices is better -> the one with minimum operations
// print the minimum operations required

// so, given n matrix dimensions, print the minimum cost to multiply them to a single matrix
// to multiply n matrices, there are lot of ways
// hence since we can solve this in different patterns, it is a PARTITION DP problem

// Given arr[] - {10, 20, 30, 40, 50} <- dimensions of n-1 matrices
// dimension of A is 10x20
// dimension of B is 20x30
// and so on Dimension of D is 40x50
// 1st matrix -> A[0] x A[1]
// 2nd matrix -> A[1] x A[2] and so on
// so ith matrix -> A[i-1] x A[i]

// start with all the matrices, and try all ways
// whichever gives minimal, return that answer
// i -> start = A
// j -> end = D 
// always mark the start and end point in each subproblem

// RULES FOR PARITION DP
// 1) Start with the entire block/array and mark start and end points f(i,j)
// 2) Try all partitions 
// 2.5) Run a loop to try all partitions
// 3) Return the best possible 2 partitions

// f(i,j)
// think in terms of the array 10 20 30 40 50
// We can say A -> 20, B -> 30, C -> 40, D -> 50, and size of each matrix is previous element x current element
// so i starts at A, j ends at D
// so i is 1 (index wise), j is n-1
// f(1, 4) -> solve matrix 1 to 4, return minimum multiplication to multiply matrix 1 to matrix 4

// f(i,j)
// when we do partitoning, i and j shrinks
// minimum dist between i & j is -> when it is a single array
// so base case
// if(i == j) return 0;
// NOW TRY ALL PARTITIONS
// run a loop k from i to j-1
// this k is the partition, compute f(i, k), f(k+1, j)
// this covers all partitions

// take the best of all answers
// for each case, number of steps required is:
// steps = A[i-1] x A[k] x A[j] + f(i, k) + f(k+1, j) // RECURSIVE
// return minimal of all steps

// THE K LOOP IS THE PARTITION LOOP

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + f(i,k,arr, dp) + f(k+1,j,arr, dp);
        if(steps < mini) mini = steps;
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N-1, arr, dp);
}

// THE ABOVE IS A MEMOIZATION CODE WHICH WILL GIVE TLE FOR SOME CASES
// Below is the tabulation code

// 1) copy the base case
// dp[n][n]
// for every i == j, fill 0
// for(i=1; i<N; i++)
// dp[i][i] = 0

// 2) write the changing parameters
// i & j
// i started from 1 and moved ahead
// so start i from n-1 to 0
// and j (ideally) from 1 to N-1
// but this doesnt make sense
// because i has to always be in left of j
// so j will be i+1 to N-1

// 3) copy the recurrence

int matrixMultiplication(vector<int> &arr, int N){
    int dp[N][N];
    for(int i = 1; i < N; i++) dp[i][i] = 0;
    for(int i = N-1; i >= 1; i--){
        for(int j = i+1; j < N; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                if(steps < mini) mini = steps;
            }

            dp[i][j] = mini;
        }
    }


    return dp[1][N-1];
}