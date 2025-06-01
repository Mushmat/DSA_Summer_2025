#include <bits/stdc++.h>
using namespace std;


void printn(int n){ //Prints linearly from N to 1
    if(n <= 0){
        return;
    }
    cout << n << endl;
    printn(--n);
}

void print1(int n, int i = 1){ //Prints linearly from 1 to N
    if(i > n){
        return;
    }
    cout << i << endl;
    print1(n, ++i);
}
int main() {
    
    int n;
    cin >> n;
    printn(n);
    cout << endl;
    print1(n);
    return 0;
}