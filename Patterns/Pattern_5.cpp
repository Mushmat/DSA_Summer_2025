#include <bits/stdc++.h>
using namespace std;

int main() {
    
    /*
    *****
    ****
    ***
    **
    *
    */

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        //We are printing, total_rows - row_number + 1, these number of stars at every row
        for(int j = 0; j < n-i+1 ; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}