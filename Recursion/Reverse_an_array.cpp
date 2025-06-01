#include <bits/stdc++.h>
using namespace std;

//Reverse the array using two pointer recursion
void reversearray(int arr[], int l, int r){
    if(l == r) return;
    if(l > r) return;
    swap(arr[l], arr[r]);
    reversearray(arr, l+1, r-1);
}

int main() {
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    reversearray(arr, 0, n-1);
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}