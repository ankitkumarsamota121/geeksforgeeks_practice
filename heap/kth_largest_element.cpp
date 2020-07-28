#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int main() {
    int t, n, k;
    vector<int> a(N);
    vector<int> ans;
    cin >> t;
    while (t--) {
        cin >> k >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (pq.size() < k) {
                pq.push(a[i]);
                if (pq.size() == k) {
                    ans.push_back(pq.top());
                } else {
                    ans.push_back(-1);
                }
                continue;
            }

            if (a[i] > pq.top()) {
                pq.pop();
                pq.push(a[i]);
            }
            ans.push_back(pq.top());
        }

        for (auto x : ans)
            cout << x << ' ';
        cout << endl;

        a.clear();
        ans.clear();
    }

    return 0;
}