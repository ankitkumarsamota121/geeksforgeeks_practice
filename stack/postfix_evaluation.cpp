#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    return true;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--)
    {
        string exp{};
        char ch{};
        int x1, x2, r;
        getline(cin, exp);
        stack<int> s;
        for (int i = 0; i < exp.length(); i++)
        {
            if (isOperand(exp[i]))
                s.push(exp[i] - '0');
            else
            {
                x2 = s.top();
                s.pop();
                x1 = s.top();
                s.pop();
                switch (exp[i])
                {
                case '+':
                    r = x1 + x2;
                    s.push(r);
                    break;
                
                case '-':
                    r = x1 - x2;
                    s.push(r);
                    break;
                
                case '*':
                    r = x1 * x2;
                    s.push(r);
                    break;
                
                case '/':
                    r = x1 / x2;
                    s.push(r);
                    break;
                
                default:
                    break;
                }
            }
        }

        cout << s.top() << endl;  
    }

    return 0;
}