#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        string s;
        cin >> s;

        stack<pair<char, int>> st;

        int open = 0;

        for (auto c : s) {
            if (c == '(') {
                cout << ++open << ' ';
                // open++;
                st.push({c, open});
            }
            if (c == ')') {
                cout << st.top().second << ' ';
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}