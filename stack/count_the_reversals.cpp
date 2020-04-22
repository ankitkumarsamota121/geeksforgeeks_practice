#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while(t--)
    {
        string s;
        stack<char> st;
        getline(cin, s);
        string left{};
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '{')
                st.push(s[i]);
            else if(!st.empty())
                st.pop();
            else
                left += s[i];
        }

        int m = st.size();
        int n = left.length();

        if (abs(m-n) % 2 == 0)
            cout << ceil(m/2.0) + ceil(n/2.0) << endl;
        else
            cout << -1 << endl;

    }
    return 0;
}