//Arrays and Strings
#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[5]; //Creates an array of size 5, all indexes can store an integer -> i = 0, 1, 2, 3, 4
    //Arrays can be modified and operations can be done.
    //cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];

    //Array are stored in contiguous memory locations.
    //2D Array
    int twod[3][5]; //row, column
    twod[1][3] = 78;
    cout << twod[1][3] << endl;
    cout << twod[1][2] << endl; //returns garbage

    //Strings also store every character in an index.
    string s ="World";
    cout << s[2] << endl; //prints r
    int len = s.size();
    cout << s[len-1] << endl; //prints d
    //Characters can be changed.
    return 0;
}