//Always give the interviewer a brute force solution first
//Then give them a better solution by optimizing the brute
//Then optimize the better to get the most optimal solution

/*  Bruteforce
    Sort the array
    Return the last index element
    In order to sort in best time, we need O(nlogn) time, and space complexity if quicksort is done then O(1)
*/

/*
    Optimal Solution
    Keep a largest variable and initialize it to the first element
    Traverse through the array to check which element is greater than the largest element stored. If greater, then change the largest element to that element
    Once the traversal ends, you'll have the maximum element
    This takes O(n) time since only one traversal is done and no sorting needed
*/
