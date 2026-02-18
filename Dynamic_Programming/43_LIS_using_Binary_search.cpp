// we need LIS but here we will use binary search to get the LIS
// go to each element and check in what all subsequences that element can be
// but this takes a lot of time & space

// since we only need the length of LIS
// what we can do is, make subsequence at every element, whenever a element comes such that it cannot fit in the existing subsequence,
// check where that element can fit, and insert that element to that subsequence
// the length of the final array after replacing with new elements, is the length of the LIS

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]);
            temp[ind] = arr[i];
        }
    }

    return temp.size();
}
// however the temp array does not contain the actual LIS, it is just there to generate the length of the LIS
