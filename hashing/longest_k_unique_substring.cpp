#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k;
    string str;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        cin >> str;
        cin >> k;

        queue<char> q;
        unordered_map<char, int> m;

        int i = 0;
        int ans = -1;
        while (i < str.length()) {
            q.push(str[i]);
            m[str[i]]++;
            while (m.size() > k) {
                m[q.front()]--;
                if (m[q.front()] == 0) {
                    m.erase(q.front());
                }
                q.pop();
            }

            if (m.size() == k)
                ans = max(ans, int(q.size()));
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}