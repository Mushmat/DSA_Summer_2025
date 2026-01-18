#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int t;
    cin >> t;
    for(long long int i = 0; i < t; i++){
        long long int n;
        cin >> n;
        vector<long long int> arr(n); // sorted
        for(long long int j = 0; j < n; j++){
            cin >> arr[j];
        }

        vector<long long int> org = arr; // org is the original

        sort(arr.begin(), arr.end());

        map<long long int, long long int> mp;
        // 0  means Red
        // 1 means blue

        long long int number = 0;
        for(long long int j = 0; j < n; j++){
            mp.insert({arr[j], number});
            if(number == 0) number = 1;
            else if(number == 1) number = 0;
        }

        queue<long long int> q;

        for(long long int j = 0; j < n; j++){
            q.push(org[j]);
        }

        long long int found = -1;
        while(!q.empty()){
            long long int topelement = q.front();
            q.pop();
            if(mp.find(topelement) != mp.end() && mp[topelement] == 0){
                if(q.empty()) continue;
                long long int secondelement = q.front();
                if(mp.find(secondelement) != mp.end() && mp[secondelement] == 0){
                    found = 1;
                }
            }
            else if(mp.find(topelement) != mp.end() && mp[topelement] == 1){
                if(q.empty()) continue;
                long long int secondelement = q.front();
                if(mp.find(secondelement) != mp.end() && mp[secondelement] == 1){
                    found = 1;
                }
            }
        }

        if(found == 1){
            cout << "No" << endl;
        }
        if(found == -1){
            cout << "Yes" << endl;
        }
    }

    return 0;
}

// PRETESTS Passed