// Patterns and templates for sliding window problems
// 4 kind of patterns are generally seen

// 1) Constant Window
// eg: given an array of +ve and -ves, and given a number k. find out the max sum of k consecutive elements in the array
// here size stays k everytime
// here we take two pointers l = 0, r = k-1th index
// and run a loop to get the sum of this window
// after which we move l and r by 1 each
// and keep on doing this till r doesnt cross the boundary

// 2) Longest Subarray or Substring with condition
// eg longest subarray with sum <= k
// -> start with brute force
// -> then better, then optimal
// -> brute is to generate all the subarrays and check with the condition
// -> better is to implement two pointer and sliding window
// -> start with window size of 1
// window has a left and a right
// take initial sum as 0
// now either we can expand the window or shrink the window
// usually expansion happens for r (right), and shrinking for l (left)
// here, increase the window size and look for the sum
// when the sum exceeds k, then shrink

// 3) 