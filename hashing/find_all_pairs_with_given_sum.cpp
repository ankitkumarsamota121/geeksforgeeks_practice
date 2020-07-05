#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n, m, x, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;

        unordered_map<ll, ll> A;
        vector<pair<ll, ll>> v;

        for (int i = 0; i < n; i++) {
            cin >> a;
            A[a] = 1;
        }

        for (int i = 0; i < m; i++) {
            cin >> b;
            if (A[x - b]) {
                v.push_back({x - b, b});
            }
        }

        if (v.size() == 0) {
            cout << -1 << endl;
        } else {
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size() - 1; i++) {
                cout << v[i].first << ' ' << v[i].second << ", ";
            }
            cout << v[v.size() - 1].first << " " << v[v.size() - 1].second << endl;
        }
    }
    return 0;
}