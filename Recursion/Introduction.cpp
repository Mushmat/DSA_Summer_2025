#include <bits/stdc++.h>
using namespace std;
//An introduction program for recursion. Simply prints numbers from 0 to 5.
int cnt = 0;

void printc(){
    if(cnt >= 6){
        return;
    }
    cout << cnt << endl;
    cnt++;
    printc();
}
int main() {
    
    printc();
    return 0;
}