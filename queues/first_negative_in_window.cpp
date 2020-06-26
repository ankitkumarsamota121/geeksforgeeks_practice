#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    int a[100005];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;

        vector<int> ans;
        queue<int> q;

        // Insert first k elements into the queue
        for (int i = 0; i < k; i++) {
            q.push(i);
        }

        for (int i = k; i < n; i++) {
            // Find the ans for previous window
            while (!q.empty() and a[q.front()] >= 0) {
                q.pop();
            }
            ans.push_back((q.empty() ? 0 : a[q.front()]));

            // Push the next element
            q.push(i);

            // Remove the elements that are not the part of the current window
            if (q.front() <= i - k) {
                q.pop();
            }
        }

        while (!q.empty() and a[q.front()] >= 0) {
            q.pop();
        }
        ans.push_back((q.empty() ? 0 : a[q.front()]));

        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}