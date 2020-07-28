#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m, x;
    vector<int> a;
    vector<int> b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
            mp[x]++;
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            while (mp[x] > 0) {
                cout << x << ' ';
                mp[x]--;
            }
        }

        for (auto p : mp) {
            while (mp[p.first] > 0) {
                cout << p.first << ' ';
                mp[p.first]--;
            }
        }
        cout << endl;

        a.clear();
        b.clear();
    }
    return 0;
}