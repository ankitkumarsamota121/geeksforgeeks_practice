#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[105];
    int ans[105];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                ans[i] = -1;
                s.push(a[i]);
            } else {
                while (!s.empty() && s.top() >= a[i])
                    s.pop();

                ans[i] = (s.empty() ? -1 : s.top());
                s.push(a[i]);
            }
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}