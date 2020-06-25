#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        string s;
        string ans;
        int count = 0;
        char pre_c = ' ';
        cin >> s;

        stack<pair<char, int>> st;

        for (auto c : s) {
            c = towlower(c);
            if (c == pre_c) {
                count++;
            } else {
                ans += to_string(count);
                ans += pre_c;
                pre_c = c;
                count = 1;
            }
        }

        cout << ans << endl;
    }
}