#include <bits/stdc++.h>
using namespace std;

void subsets(string in, string out, int i, vector<string> &v) {
    if (i == in.length()) {
        // cout << out << endl;
        if (out != "") v.push_back(out);
        return;
    }

    subsets(in, out + in[i], i + 1, v);
    subsets(in, out, i + 1, v);
}

int main() {
    int t, n;
    string in;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> in;
        vector<string> v;
        subsets(in.substr(0, n), "", 0, v);
        sort(v.begin(), v.end());
        for (string s : v) {
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}