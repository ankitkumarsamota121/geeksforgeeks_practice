#include <bits/stdc++.h>
using namespace std;

int findMaxOneCount(int arr[], int n) {
    int orig_one_count = 0;

    int max_diff = 0;

    int curr_max = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            orig_one_count++;
        }

        int val = (arr[i] == 1) ? -1 : 1;

        curr_max = max(val, curr_max + val);
        max_diff = max(max_diff, curr_max);
    }
    max_diff = max(0, max_diff);

    // cout << orig_one_count << ' ' << max_diff << endl;

    return orig_one_count + max_diff;
}

int main() {
    int t, n;
    int a[10005];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << findMaxOneCount(a, n) << endl;
    }
    return 0;
}