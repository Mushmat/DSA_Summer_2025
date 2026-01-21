// Ninja is planning this N days long training schedule. 
// each day he can perform any one of these three activites (Running, Fighting Practice, or Leadrning New Moves)
// Each activity has some merit points on each day. AS ninja has to improve all his skills, he cant do the same activity in two consecutive days. 
// Can you help ninja find out the maximum merit points ninja can earn?

// you are given a 2d array of size n * 3 "POINTS", with the points corresponding to each dayy and activity.
// your task is to calculate the maximum number of merit points that Ninja can earn

// greedy fails here
// we need to try all possible ways, therefore RECURSION

// we can treat day numbers as indices, day 0 is index 0, and so on
// in order to select a task on any day i, we  need to know what was the last task performed
// therefore for each day (which is the index), we need the last variable that tells which task was done last day
// if last is 0, task 0 was done, if last is 1, task 1 was done, and so on
// if last is 3, that means no task was done. however this only arises on Day 0
// f(n-1, 3) states return the max merit points on the array that starts from 0, ends at n-1, and 3 means no task was performed on the nth day
// f(2, 1) give the max merit points from 0 to 2nd index if on 3rd index, task 1 was performed

// are there overlapping subproblems for scope of memoization? Yes
// therefore simply memoize

// here two parameters are being memoized
// since last can be either 0, 1, 2,3
// so dp[n][4] is required here instead of dp[n] in other problems

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(day ==0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int task = 0; task < 3; task++){
        if(task != last){
            int points = points[day][task] + f(day-1, task, points, dp);
            maxi = max(maxi, points);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){

    vector<vector<int>> dp(n, vector<int> (4, 0));

    return f(n-1, 3, points, dp);
}

// NEXT IS TABULATION AND SPACE OPTIMIZATION

int ninjaTraining(int n, vector<vector<int>> &points){

    vector<vector<int>> dp(n, vector<int> (4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], points[0][2], points[0][3]);

    for(int day = 1; day < n; day ++){
        for(int last = 0; last < 4; last++){
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    int points = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }

    return dp[n-1][3];
}

// the above code can be optimized for space

int ninjaTraining(int n, vector<vector<int>> &points){

    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][1], points[0][2], points[0][3]);

    for(int day = 1; day < n; day ++){
        vector<int> temp(4,0);

        for(int last = 0; last < 4; last++){
            temp[last] = 0;

            for(int task = 0; task < 3; task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]); // dp day -1 is a previous state hence can be changed for optimization
                }
            }
        }
        prev = temp;
    }

    return  prev[3];

}

// TC : O(N x 4 x 3)
// SC: O(4) as good as constant