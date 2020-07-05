#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n1, n2, n3, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n1 >> n2 >> n3;

        map<ll, ll> ma;
        map<ll, ll> mb;
        map<ll, ll> mc;

        for (int i = 0; i < n1; i++) {
            cin >> a;
            ma[a] = 1;
        }
        for (int i = 0; i < n2; i++) {
            cin >> b;
            mb[b] = 1;
        }
        for (int i = 0; i < n3; i++) {
            cin >> c;
            mc[c] = 1;
        }

        bool flag = true;

        for (auto p : ma) {
            if (mb[p.first] and mc[p.first]) {
                cout << p.first << ' ';
                flag = false;
            }
        }

        if (flag) {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}