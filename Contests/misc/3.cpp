#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;                                   
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        long long dec = 0, inc = 0;          
        for (int i = 0; i < n; ++i) {
            long long diff = a[i] - b[i];
            if (diff > 0)      dec += diff;   
            else               inc += -diff;  
        }

        long long ans = (dec == 0 && inc == 0)
                        ? 1
                        : max(dec, inc) + 1;

        cout << ans << '\n';
    }
    return 0;
}