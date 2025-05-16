#include <bits/stdc++.h>
using namespace std;

int main(){
    int marks;
    cin >> marks;
    if(marks >= 80){
        cout << "A" << endl;
        return 0;
    }
    else if(marks >=60){
        cout << "B" << endl;
        return 0;
    }
    else if(marks >= 50){
        cout << "C" << endl;
        return 0;
    }
    else if(marks >= 45){
        cout << "D" << endl;
        return 0;
    }
    else if(marks >= 25){
        cout << "E" << endl;
        return 0;
    }
    else{
        cout << "F" << endl;
        return 0;
    }

}