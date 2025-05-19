#include <bits/stdc++.h>
using namespace std;

int main() {
    
    /*
    *
    **
    ***
    ****
    *****
    */
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n; i++){ //n rows
        //for 0th row, printing 1 star
        //fir 1st row, printing 2 stars etc

        for(int j = 0; j <=i; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}