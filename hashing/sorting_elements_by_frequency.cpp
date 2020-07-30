#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main() {
    int t, n;
    int a[200];
    int freq[100];
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }

        vector<pair<int, int>> v;
        for (auto p : m)
            v.push_back({p.first, p.second});

        sort(v.begin(), v.end(), compare);

        for (auto p : v) {
            int temp = p.second;
            while (temp--) {
                cout << p.first << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}