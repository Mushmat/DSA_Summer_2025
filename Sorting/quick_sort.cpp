// sorts the array in ascending order 
// TC: O(nlogn) but the space complexity is O(1). So it is better than merge sort in terms of sorting
// Step 1: Pick a pivot: any element of the array. 
// Step 2: Once you pick a pivot, say the first element of the given array, place that element in the correct place
// Step 3: Doesnt matter what you pick as a pivot, picking every element eventually sorts the array
// Step 3: Once you pick the pivot, keep all the smaller elements on the left and the larger elements at the right.
// Step 4: Repeat the steps
/*
    point low to the 0th index 
    point high to the last index 
    pivot = array[low]
    keep i at the first element 
    keep j at the last element
    start with i and check which element is greater than the pivot
    start with j and check which element is smaller than the pivot
    swap these two elements
    repeat until i and j come to the same index or j crosses i
    keep the pivot at the index where j stopped
    the pivot is now at the correct place
    Now the pivot behaves as a partition index. The array to the left of it is not sorted, right of it is not sorted.
    therefore, one array is from low to partition - 1 & other is from partition + 1 to high
    recurse and sort the complete array

    qs(arr, low, high){
        if(low < high){
            partitionindex = f(arr, low, high) // A function which finds a pivot and places it at the correct place
            qs(arr, low, partitionindex - 1);
            qs(arr, partitionindex + 1, high);
        }
    }

    int f(arr, low, high){
        pivot = arr[low];
        i = low;
        j = high;
        while(i < j){
            while(arr[i] <= arr[pivot] && i <= high) {i++}
            while(arr[j] >= arr[pivot] && j >= low) {j--}
            //Above two lines find the first element greater than pivot at i, and lesser than pivot at j; without crossing each other
            if(i<j) swap(arr[i], arr[j]);    
        }
        swap(arr[low], arr[j]) //Pivot swapping
        return j;   
    }
*/