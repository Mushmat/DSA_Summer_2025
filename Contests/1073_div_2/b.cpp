#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;

        vector<long long int> a(n);
        for (long long int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long int> vis(n + 2, 0);
        for (long long int x : a) {
            if (x <= n) vis[x] = 1;
        }

        long long int mex = 0;
        while (vis[mex]) mex++;

        if (mex == 1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}    