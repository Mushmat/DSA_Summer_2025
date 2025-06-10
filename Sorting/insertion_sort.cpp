// Takes an element and places it on its correct position
// Start with the first element, keep increasing the number of elements and check whether the coming number is on its correct position
// If not, then put the element in the correct position
// To put the element in the correct posn, keep going left and keep swapping till it can be done
/*
    Psuedo
    for(i = 0; i <= n-1; i++){
        j = i;
        while(j > 0 && a[j-1] > a[j]){
            swap them
            j--;
        }
    }
    
    Again TC = O(n^2) (worst case, avg case)
    For best case the loop doesnt run a single time when array is already sorted. Therefore the best case is O(N)
*/