#include <bits/stdc++.h>
using namespace std;

void postorder(int pre[], int n, int& idx, int minVal, int maxVal) {
    // Base Case
    if (idx == n) {
        return;
    }
    int val = pre[idx];

    // Recursive Case
    if (val > minVal && val < maxVal) {
        idx++;
        postorder(pre, n, idx, minVal, val);
        postorder(pre, n, idx, val, maxVal);

        cout << val << " ";
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int pre[1005];
        for (int i = 0; i < n; i++) cin >> pre[i];
        int idx = 0;
        postorder(pre, n, idx, INT_MIN, INT_MAX);
        cout << endl;
    }
    return 0;
}