#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        string s;
        string ans;
        cin >> s;

        int count = 1;
        char pre_c = tolower(s[0]);

        for (int i = 1; i < s.length(); i++) {
            char c = s[i];
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

        ans += to_string(count);
        ans += pre_c;

        cout << ans << endl;
    }
}