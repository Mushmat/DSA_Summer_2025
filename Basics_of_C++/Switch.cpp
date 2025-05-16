//Switch Statements
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

//If you dont give break after cases, once that case is executed, all the cases below it will also be executed.
    switch(n){
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "SAturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        default:
            cout << "Invalid" << endl;
    }

    return 0;
}