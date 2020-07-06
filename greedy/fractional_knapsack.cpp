#include <bits/stdc++.h>
using namespace std;

#define pff pair<float, float>
#define ff first
#define ss second

bool compare(pff p1, pff p2) {
    return (p1.ff / p1.ss) >= (p2.ff / p2.ss);
}

int main() {
    int t, n;
    float w, vi, wi;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        vector<pff> v;
        for (int i = 0; i < n; i++) {
            cin >> vi >> wi;
            v.push_back({vi, wi});
        }

        sort(v.begin(), v.end(), compare);

        float ans = 0;

        int i = 0;
        while (w > 0 and i < n) {
            auto p = v[i];
            if (w >= p.ss) {
                ans += p.ff;
                w -= p.ss;
            } else {
                ans += (w * (p.ff / p.ss));
                w = 0;
            }
            i++;
        }

        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}