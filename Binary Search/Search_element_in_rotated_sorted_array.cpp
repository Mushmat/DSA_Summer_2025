// Given a rotated sorted array at some point (unique elements only)
// Given a target
// Find the index of the target

// find the sorted half, whether left is sorted or right
// only check in the sorted halves
// to check whether a half is sorted or not, low <= mid or high
// f(arr, n, target)
/*
{
    low = 0, high = n -1
    while(low <= high){
        mid = low + high / 2;
        if(arr[mid] == target) return mid;
        //left sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        //right sorted
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
        return -1
}
*/
