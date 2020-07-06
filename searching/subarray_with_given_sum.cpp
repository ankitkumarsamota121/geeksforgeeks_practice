#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n, s, a;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<ll> v;
        vector<ll> pre;
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> a;
            v.push_back(v[i - 1] + a);
        }

        int i = 1;
        int j = 1;
        bool flag = true;
        while (j <= n) {
            ll sum = v[j] - v[i - 1];
            while (sum > s) {
                i++;
                sum = v[j] - v[i - 1];
            }
            if (sum == s) {
                flag = false;
                cout << i << ' ' << j << endl;
                break;
            }
            j++;
        }

        if (flag) {
            cout << -1 << endl;
        }
    }
    return 0;
}