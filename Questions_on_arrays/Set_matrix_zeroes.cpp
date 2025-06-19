// Given an n x m matrix containing only zeroes and ones
// Find zeroes. For every zero that exists, mark its entire row and its entire column as zero
// Brute:
// Iterate and find the first zero
// and for that zero, mark all the one's as -1s for its row and column
// Move ahead and do it for every zero
// Do one iteration more to convert every -1 to a 0 now
// O(N^3)

// Better:
// For any 1 to be converted to 0, the row in which that 1 lies, must have atleast one 0, or the column in which 1 lies, must have atleast one 0
// Track that column/row to be marked 0 later 
// Therefore we need to have track of n rows and m columns
// Create a m size column array
// Create a n size row array
// Initially mark as 0
// Whenever you get a 0, mark that row and column as 1
// Do it for every 0 you get
// Once iteration is done, reiterate again and change every 1 to a 0 if either that row is marked or the column is marked
// O(n^2) and space is also there
