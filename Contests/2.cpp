#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;

        long long sum = 0;
        long long zeros = 0;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            sum += x;
            if(x == 0) zeros++;
        }

        cout << (sum + zeros) << endl;
    }

    return 0;
}