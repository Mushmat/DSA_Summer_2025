#include <bits/stdc++.h>
using namespace std;
//Sums the first n integers by recursion
//Parameterised way
void firstn(int n, int &sum){
    if(n == 0) {
        cout << sum << endl;
        return;
    }
    sum+=n;
    n--;
    firstn(n, sum);
}

int main() {
    
    int n, sum = 0;
    cin >> n;
    firstn(n, sum);
    return 0;
}