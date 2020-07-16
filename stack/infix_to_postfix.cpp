#include <bits/stdc++.h>
using namespace std;

int f(char c) {
    if (c == '+' or c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

int main() {
    int t;
    string exp;
    cin >> t;
    while (t--) {
        cin >> exp;
        stack<int> s;
        string ans;

        for (auto c : exp) {
            // cout << c << endl;
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                while (!s.empty() && s.top() != '(' && f(s.top()) >= f(c)) {
                    ans += s.top();
                    s.pop();
                }
                s.push(c);
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (s.top() != '(') {
                    ans += s.top();
                    s.pop();
                }
                s.pop();
            } else {
                ans += c;
            }
            // cout << ans << endl;
        }
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        cout << ans << endl;
    }
    return 0;
}