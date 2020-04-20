#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--)
    {
        bool flag = true;
        string paren{};
        int c_i{}, i{};
        getline(cin, paren);
        stack<int> st;
        for(auto &c : paren)
        {
            c_i = static_cast<int>(c);
            // std::cout << c_i << endl;
            if(c_i == 40 || c_i == 91 || c_i == 123)
                st.push(c_i);
            else
            {
                if (st.empty())
                    flag = false;
                else
                {
                    i = st.top();
                    st.pop();
                    if (i - c_i > 2)
                        flag = false;
                }
            }  
        }

        if (!st.empty())
            flag = false;

        if (flag)
            cout << "balanced\n";
        else
            cout << "not balanced\n";
    }

    return 0;
}