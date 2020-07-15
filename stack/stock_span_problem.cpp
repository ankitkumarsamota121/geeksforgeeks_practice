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
        int span[805]{0};

        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                ans[i] = 1;
                span[a[i]] = 1;
                s.push(a[i]);
            } else {
                int cnt = 1;
                while (!s.empty() && s.top() <= a[i]) {
                    cnt += span[s.top()];
                    s.pop();
                }
                s.push(a[i]);
                ans[i] = cnt;
                span[a[i]] = cnt;
            }
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}