#include <bits/stdc++.h>
using namespace std;

bool allTrue(int m[], int st[]) {
    for (int i = 0; i < 26; i++) {
        if (m[i] == 0 && st[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.length();

        int st[26]{0};
        for (auto c : s) {
            st[c - 'a']++;
        }

        int i = 0, j = 0;
        int len = n;
        int m[26]{0};

        while (j < n) {
            m[s[j] - 'a']++;
            while (allTrue(m, st)) {
                m[s[i] - 'a']--;
                len = min(len, j - i + 1);
                i++;
            }
            j++;
        }

        cout << len << endl;
    }
}