#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    m[4] = 4;
    m[5] = 5;

    auto it = m.begin();

    // cout << m.erase((*it).first) << endl;
    m.erase((*it).first);

    for (auto p : m) {
        cout << p.first << endl;
    }

    return 0;
}