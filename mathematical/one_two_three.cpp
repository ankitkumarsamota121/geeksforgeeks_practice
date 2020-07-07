#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[1000005];
    cin >> t;
    while (t--) {
        cin >> n;
        bool b[1000005]{0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int x = a[i];
            if (x == 0) {
                b[i] = 1;
            }
            while (x) {
                int d = (x % 10);
                if (d > 3 or d == 0) {
                    b[i] = 1;
                    break;
                }
                x /= 10;
            }
        }

        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                v.push_back(a[i]);
            }
        }

        sort(v.begin(), v.end());
        if (v.size() == 0) {
            cout << -1 << endl;
        } else {
            for (auto x : v) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}