#include <bits/stdc++.h>
using namespace std;

//Print your name N times, where name and N are input.

void printname(string name, int n){
    if (n <= 0){
        return;
    }
    cout << name << endl;
    n--;
    printname(name, n);
}
int main() {
    
    string name;
    int n;

    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Enter number of times: " << endl;
    cin >> n;

    printname(name,n);
    return 0;
}