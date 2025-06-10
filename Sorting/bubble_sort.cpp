// pushes the maximum to the last
// does it by adjacent swapping
// compares two elements, are they sorted. if yes, move to next
// if not sorted, swap it.
// move ahead
// this pushes the maximum element to the last index
// We can observe it to be the opposite of what selection sort does
// after one round of adjacent swap checks, the max element is at the last
// after this round, we can ignore the last element and perform the same algo on n-1 remaining elements of the array
// therefore after each iteration, one element is at its correct position
/*
    Psuedo
    for(i = n - 1; i > 1; i--){
        for(j = 0; j <= i-1; j++){
            if(a[j] > a[j+1]) swap them
        }
    }

    Time complexity is O(n^2) (worst and average)
    Best case runs for O(N) when the array is sorted itself. On the first run then, no swap is done and the algo doesnt move forward since array is already sorted.

*/