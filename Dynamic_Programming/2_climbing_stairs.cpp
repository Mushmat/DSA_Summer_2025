// given a number of stairs
// initially you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps
// you are supposed to return the number of distinct ways in which yu can climb from 0th step to nth step

// how to understand this is a dp problem?
// -> count the total number of ways... type of problem
// -> which way gives the min or max output if there are multiple ways... type of problem
// in these kind of questions, we tend to apply recursion
// if recursion comes in, then DP can also come in

// in this question, if n = 3, we can take 0 - 1, 1 - 2, 2 - 3;  or we can take  0 -1, 1 - 3; or 0 - 2, 2 - 3. these are 3 ways
// since we need all possible ways, we use DP here

// we are at 0 and have to reach n
// f(n) gives no of ways from 0 to n
f(index){
    if(index == 0) return 1;
    if(index == 1) return 0;
    // do everything that is possible on index
    left  = f(index - 1) // 1 jumps
    right = f(index - 2) // 2 jumps
    return left + right;

}

// now it can be memoized, tabulised, and space optimized easily

