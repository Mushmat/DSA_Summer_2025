#include <bits/stdc++.h>
using namespace std;

int main() {

    /*
    -> prestore and fetch
    -> say we need to get the number of times a given number appear in an array
    -> say we also tell that the maximum number in that array is 12. that means, all the numbers greater than 12, appear 0 times in the array
    -> so we now create an array of size 13 (indexing 0 to 12) and assign everything to 0 initially. This is the Hash Array
    -> |0|0|0|0|0|0|0|0|0|0|0|0|0|
    -> In the precalculation step, for each index 0 to 12, store the number of times that index appears in the array. For example if 3 appears twice, then at index 3, store 2
    -> Others that do not appear, remain 0
    -> Now we can simply return the count of any number by doing hash[number]
    */

    int n; //number of elements in the array
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    //precompute    
    int hash[13] = {0};
    for(int i = 0 ; i< n; i++){
        hash[arr[i]] +=1;
    }
    
    int c; //number of test case or queries
    cin >> c;
    while(c--){
        int number;
        cin >> number;
        //fetch
        cout << hash[number] << endl;
    }
    return 0;

    /*
    -> The array size can be larger.
    -> A size of 1e6 is the maximum size permissible in int main. (for integers)
    -> A size of 1e7 is the maximum permissible size globally. (for integers)
    */
}