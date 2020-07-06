#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        cin >> s;
        bool f = false;
        while (next_permutation(s.begin(), s.end())) {
            int d = (s.back() - '0');
            if (d % 2 == 0) {
                f = true;
                cout << s << endl;
                break;
            }
        }
        if (!f) {
            cout << -1 << endl;
        }
    }
    return 0;
}