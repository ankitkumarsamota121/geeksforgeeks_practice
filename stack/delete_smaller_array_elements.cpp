#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;

        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push(a[i]);
            } else {
                while (!s.empty() and s.top() < a[i] and k > 0) {
                    s.pop();
                    k--;
                }
                s.push(a[i]);
            }
        }

        stack<int> ans;
        while (!s.empty()) {
            ans.push(s.top());
            s.pop();
        }

        while (!ans.empty()) {
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}