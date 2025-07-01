// given two arrays of either equal size or of different sizes (but each sorted)
// we need to find the median of them (combined)
// when total number of elements are even, we dont a defined median in the array, hence we avearage out the two middle elements
// for odd number of elements, the mid point element is the median simply

// one approach to merge is using the merge function of the merge sort algo
// once we have the merged array
// find the median simply
// this takes O(n) time

// Binary Search Approach:
// say we have total even number of elements
// and we merge the array and get the merged array
// goal is to formulate the correct left and right half
// put an imaginary middle line dividing the left and right half
// if we pickup no one from array 1 to put in left half, only array 2 elements can be on the left
// but if array 2 does not have that much elements, then we need to pick some element from arr 1 as well
// once left is formulated, put remaining in the right half
// but is this a valid configuration? no if this is not a sorted array
// maybe this time pick up 2 elements from arr 1 and 3 from arr 2 (considering an example of even elements (total 10))
// repeat this until you get a valid configuration

/*

    double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2) return median(b, a);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    n1 = n1 + n2;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}


*/