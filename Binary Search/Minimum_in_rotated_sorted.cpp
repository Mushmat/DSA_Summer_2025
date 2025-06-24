// Given an array that has been rotated. (unique elements)
// Find the minimum element in it
// we know that binary search always eliminates one of either left side or the right side
// again, first identify the sorted half
// The part which is not sorted, is the part from where rotation has been done
// That part (not sorted one) will contain the minimum since it was the point of rotation and the array was sorted initially
// but this theory might fail
// sorted half may or may not have the answer
// therefore, to check 
// pick the minimum from the sorted half and store and eliminate that half
// next pick the minimum again from the left half, store and eliminate that half
// repeat till low <= high
// the minimum of all the picks is the answer