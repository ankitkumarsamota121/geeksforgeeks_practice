#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a;
    cin >> t;
    while (t--) {
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            cin >> a;
            pq.push(a);
        }

        int n1 = 0, n2 = 0;
        int i = 0;
        while (!pq.empty()) {
            i++;
            if (i & 1) {
                n1 = (n1 * 10) + pq.top();
            } else {
                n2 = (n2 * 10) + pq.top();
            }
            pq.pop();
        }

        cout << n1 + n2 << endl;
    }
    return 0;
}