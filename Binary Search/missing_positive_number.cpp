// given an increasing array of positive integers
// figure out kth missing number
// eg if array is 2 3 4 7 11, and k = 5
// analyze that positive numbers are 1 2 3 4 5 6 7 8 9 10 11
// 2 3 4 7 11 are already there
// 1 is the first missing number
// 5 is the second missing number
// so on 9 is the fifth missing number
// we need to return 9

// we need to find the two indexes in which the answer lies. here 7 and 11
// we can track by indexes that how many numbers are missing at a certain index
// the place where 7 is there, there should have been 4. therefore 7 - 4 = 3 numbers are missing
// the place where 11 is there, there should have been 5. therefore 11 - 5 = 6 numbers are missing
// since we need to find 5th number, it is between 7 and 11
// store the count of how many numbers are missing at each index and apply BS on that count

/*

    int missingK(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

*/