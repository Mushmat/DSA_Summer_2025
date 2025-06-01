#include <bits/stdc++.h>
using namespace std;

//Considering the first fibo is 1 and second fibo is 1
//Series then: 1 1 2 3 5 8 13 21...
int fibo(int n){
    if(n == 1 or n == 2)
    return 1;
    return fibo(n-1) + fibo(n-2);
}
int main() {
    
    int n;
    cin >> n;
    int result;
    result = fibo(n);
    cout << result << endl;
    return 0;
}