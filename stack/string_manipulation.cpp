#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        stack<string> s;
        string a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            // cout << a << endl;
            if (s.empty()) {
                s.push(a);
            } else if (s.top() == a) {
                s.pop();
            } else {
                s.push(a);
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}