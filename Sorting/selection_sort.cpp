// Get the minimum from the entire array in step 1 
// Place that minimum value at the first place and whoever is at the first place, send it to the minimum's old place
// therefore, select minimum and swap
// now we know the smallest element, select the next minimum
// again swap it with the corresponding place
// repeat this for n-1 times where n is the size of array
// after n-1 iterations, the array is sorted
// therefore it is all about getting the minimum and swapping it
/*
    pseudo:
    for(i = 0; i <= n - 2; i++){
        int min = i; //asume the first guy is the minimum
        for(j = i; j <= n-1; j++){
            if(arr[j] < arr[i]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
    
    TIME COMPLEXITY: O(n^2) since two for loops and both run for n time asymptotically.
*/