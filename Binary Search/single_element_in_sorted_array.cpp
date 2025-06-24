// Given an array having integers
// All of numbers will appear twice except one number that appears once
// Our goal is to find the element that appears once
// if you are an even index and on the right is the same element, then we can say we are still in the left part of the single element
// if you are at an odd index and on the right is the same element, then we can say we are still in the right part of the single element
// you can say that an element is a single element when the element to its right and the element to its left, are not equal to it

/*
f(arr, n){

    if(n == 1) return arr[0] //edge
    if(arr[0] != arr[1]) return arr[0] //edge
    if(arr[n-1] != arr[n-2]) return arr[n-1] //edge

    //find mid 
    //eliminate the part where the single element does not exist
    
    while(low<=high){
        mid = low + high / 2
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid]
        if((mid % 2 == 1 && arr[mid-1] == arr[mid]) or (mid % 2 == 0 && arr[mid] == arr[mid+1])){
            low = mid + 1 //eliminate left half
        }
        else{
            high = mid - 1 // eliminate right half
        }
    }

    return -1
}

*/