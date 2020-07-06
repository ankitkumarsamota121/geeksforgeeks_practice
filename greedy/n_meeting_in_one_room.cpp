#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if (p1.second.second == p2.second.second) {
        return p1.second.first <= p2.second.first;
    }
    return p1.second.second < p2.second.second;
}

int main() {
    int t, n, s, e;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, pair<int, int>>> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> e;
            v.push_back({i, {a[i], e}});
        }

        sort(v.begin(), v.end(), compare);

        vector<int> order;
        pair<int, int> p = make_pair(0, 0);
        for (int i = 0; i < n; i++) {
            if (v[i].second.first >= p.second) {
                p = v[i].second;
                order.push_back(v[i].first);
            }
        }

        for (auto x : order) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}