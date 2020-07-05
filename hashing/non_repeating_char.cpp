#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore(32767, '\n');
        cin >> s;

        unordered_map<char, int> m;
        queue<char> q;
        for (char c : s) {
            m[c]++;
            q.push(c);
        }

        while (!q.empty() and m[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << -1 << endl;
        } else {
            cout << q.front() << endl;
        }
    }
    return 0;
}