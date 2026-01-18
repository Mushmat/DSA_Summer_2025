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
// 