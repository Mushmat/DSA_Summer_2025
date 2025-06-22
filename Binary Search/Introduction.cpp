// Binary search is a searching algorithm in a restricted search space
// Iterative Code:
// we have a function that will give us the array, its size, and the target
// keep low as 0, high as size - 1 (n-1)
// while (low <= high) we can run the loop
// mid = (low + high)/2
// if(arr[mid] == target) return mid, since the element is found
// elif (target > arr[mid]) then low = mid + 1, since target on right of mid
// else high = mid - 1, since target on left of mid
// come out of the loop, means answer is not there, return -1

// Recursive Code:
// we have a recursive function taking arr, low, high
// initially low = 0, high = n-1
// if element on right, call same function with low = mid + 1
// else call function with high = mid - 1

/*
f(arr, low, high, target){

    if(low > high) return -1 // base
    mid = (low + high) / 2
    if(arr[mid] == target) return mid; //found target
    else if (target > arr[mid]){
        return f(arr, mid + 1, high, target)
    }
    else{
        return f(arr, low, mid-1, target)
    }
}

*/

// Time complexity: The time complexity of one of the best searching algorithms is none other than O(logn)

// mid = low + (high-low)/2 
// for overflow case