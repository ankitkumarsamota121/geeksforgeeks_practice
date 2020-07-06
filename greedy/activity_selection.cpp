#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first <= p2.first;
    }
    return p1.second < p2.second;
}

int main() {
    int t, n, s, e;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> e;
            v.push_back({a[i], e});
        }

        sort(v.begin(), v.end(), compare);

        int ans = 0;
        pair<int, int> p = make_pair(0, 0);
        for (int i = 0; i < n; i++) {
            if (v[i].first >= p.second) {
                p = v[i];
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}