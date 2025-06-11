// Give out the second largest element (similar ques: second smallest)

/*
    Brute Force
    Sort the array in nlogn time
    Largest element is then the array[n-1]
    But second largest element is not sure to be array[n-2] because it might happen that the largest number occurs two times in the array
    Therefore, start from n-2th index and compare whether the number is equivalent to the maximum element. If yes, move an index back. If no, then that element is the second largest element
    Since sorting is done, the asymptotic time complexity is O(nlogn)
*/

/*
    Better Solution
    In the first pass, find the largest element --> O(n)
    Keep second largest as -1 and again find that element which is second largest (that means number is greater than the current number stored in secondlargest variable, and is smaller than the largest number of the array)
    Therefore, both the passes take O(n) each, therefore TC is O(2n) which is asymptotically O(n)
*/

/*
    Optimal Solution
    Initialize largest as arr[0] and secondlargest as -1
    (assuming array does not have -ve numbers)
    Go to the second element in the array, is that greater than largest? Yes, then largest is that element, and second largest is the element which was previously largest.
    Repeat for all elements
    
    Code:

        int secondlargest(vector<int> &array, int n){
            int largest = a[0];
            int slargest = -1;
            for(int i = 0; i < n; i++){
                if(a[i] > largest){
                    slargest = largest;
                    largest = a[i];
                }
                else if(a[i] < largest && a[i] > slargest){
                    slargest = a[i];
                }
            }
            return slargest;
        }
*/