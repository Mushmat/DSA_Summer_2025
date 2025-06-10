// Better time complexity than bubble, insertion or selection sort
// A divide and conquer algorithm
// Divide the array and then merge it <-- basis of the algorithm
// Keep dividing the array till you have a single element left
// Then start merging by two pointers
// Store low and high as the start and end points of a hypothetical array
/*
    mergeSort(arr, low, high){
        //Base Case
        (if low >= high) return;

        // We first need to divide it recursively then come back merge
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        // Now we can merge them
        merge(arr, low, mid, high); //Merge the two parts that we got sorted

    }   

    merge(arr, low, mid, high){
        int temp[];
        //left array is low to mid, right array is from mid + 1 to high
        left = low;
        right = mid + 1;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]) temp.add(arr[left]); left++
            else temp.add(arr[right]); right++
        }
        //Now if one of the array gets exhausted we can simply add the rest array completely
        while(left <= mid){
            temp.add(arr[left]);
            left++;
        }

        while(right <= high){
            temp.add(arr[right]);
            right++;
        }
    }

    Now the time complexity of merge sort is O(nlogn) and it is the best complexity to sort an array.

*/