#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t;
    cin >> t;
    while (t--) {
        long long int n;
        long long c;
        cin >> n >> c;
        multiset<long long> weights;
        for (long long int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            weights.insert(temp);
        }

        long long int ans = 0;
        for (long long int i = 0; i < n; i++) {
            auto it = weights.upper_bound(c);

            if (it != weights.begin()) {
                it--;
                weights.erase(it);
            } else {
                ans++;
                weights.erase(prev(weights.end()));
            }

            if (!weights.empty()) {
                vector<long long> temp_vec;
                for (long long w : weights) {
                    temp_vec.push_back(w * 2);
                }
                weights.clear();
                weights.insert(temp_vec.begin(), temp_vec.end());
            }
        }
        cout << ans << endl;
    }

    return 0;
}
