// given an array, and a target
// assign signs either + or -, to the array elements, such that the sum of these elements is the target
// how many ways to assign signs such that the target is achieved?

// we have done s1 - s2 = D problem
// when we are assigning + -, we are assigning some portion to a subset S1, and some portion to S2
// S1 - S2 = D
// so this problem is the same as DP 18
// we have to count those partitions

// therefore the question can be read as to divide them into 2 subsets such that S1 - S2 = target, where S1 has all +, S2 has all -ve but -ve taken common
