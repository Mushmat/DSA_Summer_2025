// Send all the zeroes of the array to the end
// BRUTE FORCE
// Start by traversing the array and store all those numbers that are not zero, in a temp array
// Once you have all the non zero numbers, put all the numbers (in the temp array) to the start of the main array
// For the rest of the spaces left (the last spaces), put zeroes there 
// O(2n)

// OPTIMAL SOLUTION
// point j to the first zero
// point i to the next index of zero
// check whether i is non zero. if yes, swap them
// now move i one step and move j one step (sticking to the zero)
// again check, if i is non zero, swap
// If i is zero, move i till i becomes a non zero number and then swap with j
// Observe that j is always a zero and i points next to j.
// Stop when i crosses the boundary (when no element is left)
// hence we did the computation in a single iteration --> O(n)

