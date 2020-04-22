#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--)
    {
        string s;
        stack<char> st;
        getline(cin, s);
        int len{0};
        for (auto &a : s)
        {
            if (a == '(')
                st.push(a);
            else if (!st.empty())
            {
                st.pop();
                len += 2;
            }
        }
        cout << len << endl;
    }

    return 0;
}