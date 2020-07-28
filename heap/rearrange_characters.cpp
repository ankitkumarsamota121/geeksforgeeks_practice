#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        unordered_map<char, int> m;
        priority_queue<int> pq;
        for (auto ch : s) {
            m[ch]++;
        }

        for (auto p : m) {
            // cout << p.first << "->" << p.second << endl;
            pq.push(p.second);
        }

        int res = 0;
        int prev = -1;
        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();
            res++;
            if (prev > 0) {
                pq.push(prev);
            }
            a--;
            prev = a;
        }
        cout << (res == s.length()) << endl;
    }
    return 0;
}