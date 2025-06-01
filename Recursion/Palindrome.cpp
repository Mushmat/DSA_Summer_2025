#include <bits/stdc++.h>
using namespace std;

int checkpalindrome(string s, int l, int r){

    if(l >= r) return 1;
    if(s[l] == s[r]){
        return checkpalindrome(s,l+1,r-1);
    }
    else{
        return 0;
    }
}

int main() {
    
    string s;
    cin >> s;

    int size;
    size = s.size();

    int ans;
    ans = checkpalindrome(s,0,size-1);

    if(ans == 1) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
    
}