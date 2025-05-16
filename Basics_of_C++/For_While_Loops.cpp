#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 0; i < 10; i++){
        cout << "Hi" << " " << i << endl;
    }

    int i = 0;
    while(i < 10){
        cout << "Hi" << " " << i << endl;
        i++;
    }

    //If we put the while code into a do-while code, the code will execute for at least one time, irrespective of the condition, because
    //the code checks the 'do' first then it checks 'while'
    
    return 0;
}