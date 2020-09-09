#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main() {
    int t, n;
    int a[N], freq[N]{0};
    cin >> t;
    while (t--) {
        cin >> n;
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        int ans = -1;
        int i = 0;
        while (i < N) {
            int cnt = 0;
            while (freq[i] != 0) {
                cnt++;
                i++;
            }

            ans = max(ans, cnt);

            while (freq[i] == 0) i++;
        }

        cout << ans << endl;
    }
    return 0;
}