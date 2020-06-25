#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        string s;
        stack<char> st;
        getline(cin, s);
        int len{0};
        st.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();

                if (!st.empty())
                    len = max(len, i - st.top());
                else
                    st.push(i);
            }
        }
        cout << len << endl;
    }

    return 0;
}
