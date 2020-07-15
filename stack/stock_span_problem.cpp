#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[205];
    int ans[205];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                ans[i] = 1;
                s.push(i);
            } else {
                while (!s.empty() && a[s.top()] <= a[i]) {
                    s.pop();
                }
                ans[i] = (s.empty() ? (i + 1) : (i - s.top()));
                s.push(i);
            }
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}