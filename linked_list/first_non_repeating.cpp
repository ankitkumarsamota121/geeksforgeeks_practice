#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    char c;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<char, int> m;
        queue<char> q;
        for (int i = 0; i < n; i++) {
            cin >> c;
            q.push(c);
            m[c]++;
            while (!q.empty() and m[q.front()] > 1) {
                q.pop();
            }
            if (q.empty())
                cout << -1 << ' ';
            else
                cout << q.front() << ' ';
        }
        cout << endl;
    }
    return 0;
}