//Basics of input and output, Data types and strings. 
#include <bits/stdc++.h> //For all libraries. 
using namespace std; //Uses std for all functions


int main(){
    
    cout << "Hi!" << endl; //Output Hi and next line

    // Data Types: int
    int x = 10; //Bytes occupied: 4 and can only store from -2,147,483,648 to 2,147,483,648
    //Long
    long y = 15; //This can store more numbers than int.
    //Long Long
    long long z = 20; //Can store larger numbers than long. 
    //float
    float t = 5.5; //Occupies 4 bytes and can store from 1.2E-38 to 3.4E+38
    //Double
    double m = 6.6; //Occupies 8 bytes and can store from 2.3E-308 to 1.7E+308

    cout << x << " " << y << " " << z << " " << t << " " << m << endl;
    //String & Getline
    
    //If you input "Hello World" and want the output to be Hello World as well, define two strings, string s1, s2 and then cin and cout. 
    //If you define one string then only Hello will be picked up because space breaks the input.
    
    //string s1, s2;
    //cin >> s1 >> s2;
    //cout << s1 << " " << s2;

    //To get the entire line in one go, we need to use getline
    string str; 
    getline(cin, str);
    cout << str << endl;
    //Getline only picks up till it gets endl. Basically, one line printed at once.

    //Char
    //Stores only characters. Single quotes used. 
    char ch = 'g';
    cout << ch << endl;
    return 0;
}