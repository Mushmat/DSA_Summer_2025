// Given an array
// find the peak element : arr[i-1] < arr[i] > arr[i+1] (greater than left and greater than right)
// there can be more than 1 peak 
// for edge elements, take -inifity on their empty sides. 
// assume array has 1 peak for now
// for one element in the array, it is the peak
// for a mid, the peak can be on the right, can be on the left, or can be the mid element itself
// therefore, keep a low, mid , high
// check if mid is the peak, if yes, return
// if not, then we need to check whether peak is on the left, or on the right
// we wont have a peak on a side if that side is an increasing curve (no element goes lower than the previous one)
// therefore eliminate that side (that half)
// and the repeat
// therefore crucial is to identify on which curve is the mid. is it on the decreasing curve, then peak is on left half. is it on the increasing curve, then peak is right
// code for edge cases separately

// for multiple peaks
// the code works for multiple peaks but with a single change
// in the while loop, just write: (after writing else ifs to shrink the space based on where the peak lies) write this else, considering the mid is on the bottom section joining two curves

// else low = mid + 1


/*
    int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return mid;
        }
        else if(arr[mid] > arr[mid-1]) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
}

*/