#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--)
    {
        string str;
        getline(cin, str);
        stack<string> st;
        int start{0};
        int end{};

        for (int i = 0; i <= str.length(); i++)
        {
            if(str[i] == '.')
            {
                end = i;
                st.push(str.substr(start, end - start));
                start = i + 1;
            }
            if (i == str.length())
            {
                end = i;
                st.push(str.substr(start, end - start));
            }
        } 

        cout << st.top();
        st.pop();

        while (!st.empty())
        {
            cout << '.' << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}