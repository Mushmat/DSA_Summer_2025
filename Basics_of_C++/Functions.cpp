#include <bits/stdc++.h>
using namespace std;

//Void Function: Doesnt return anything.
void printName(){ //Non parameterised void
    cout << "Chirayu" << endl;
}

void printInputName(string name){ //Prints the name given by the user
    cout << "Hey " << name << endl;
}

//Return function: int
int sum(int num1, int num2){
    return num1 + num2;
}

int main(){
    string name;
    cin >> name;
    
    printName();
    printInputName(name);

    int num1, num2;
    cin >> num1 >> num2;
    int res = sum(num1, num2);
    cout << res << endl;
    return 0;
}