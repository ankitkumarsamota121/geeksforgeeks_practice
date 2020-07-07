#include <bits/stdc++.h>
using namespace std;

void permute(string in, string out, int i) {
    // Base Case
    if (i == in.length()) {
        cout << "(" << out << ")";
        return;
    }

    // Recursive Case
    permute(in, out + " " + in[i], i + 1);
    permute(in, out + in[i], i + 1);
}

int main() {
    int t;
    string in;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        cin >> in;
        string out;
        out += in[0];
        permute(in, out, 1);
        cout << endl;
    }
    return 0;
}