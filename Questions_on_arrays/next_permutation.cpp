// Given an array of integers
// Find the next permutation of the array
// eg the next permutation of { 3 1 2} is { 3 2 1}
// Brute:
// Generate all the permutations
// Sort them
// Find where the given array lies
// Return the next array to it
// If given array is last in order, return the first permutation
// TC: O(n! * n) at minimum

// Optimal:
// Match longer prefixes
// Then experiment with the remaining numbers of what might be the next permutation

/*
    vector<int> nextGreaterPermutation(vector<int> &A){
        int ind = -1;
        int n = A.size();
        for(int i = n -2; i >= 0; i--){
            if(A[i] < A[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(A.begin(), A.end());
        }

        for(int i = n-1; i > ind; i--){
            if(A[i] > A[ind]){
                swap(A[i] > A[ind]);
                break;
            }
        }

        reverse(A.begin() + ind + 1, A.end());
        return A;
    }
*/

// TC: O(3N)