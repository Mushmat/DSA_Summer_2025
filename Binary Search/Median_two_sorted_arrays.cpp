// given two arrays of either equal size or of different sizes (but each sorted)
// we need to find the median of them (combined)
// when total number of elements are even, we dont a defined median in the array, hence we avearage out the two middle elements
// for odd number of elements, the mid point element is the median simply

// one approach to merge is using the merge function of the merge sort algo
// once we have the merged array
// find the median simply
// this takes O(n) time

// Binary Search Approach:
// 