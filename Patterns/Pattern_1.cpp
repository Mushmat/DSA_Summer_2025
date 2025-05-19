#include <bits/stdc++.h>
using namespace std;
/*
****
****
****
****
*/
int main(){ 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){ //We have four lines
        //For every line, we print four stars
        for(int j = 0; j < n; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}