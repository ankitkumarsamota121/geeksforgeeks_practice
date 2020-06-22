#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t{};
    cin >> t;
    while(t--)
    {
        int n{};
        cin >> n;
        vector<char> nuts;
        vector<char> bolts;
        char inp;
        for (int i = 0; i < n; i++)
        {
            cin >> inp;
            nuts.push_back(n);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> inp;
            bolts.push_back(n);
        }

        array<char, 9> H{};

        for (auto &n :nuts)
        {
            switch (n)
            {
            case '!':
                H[0] = n;
                break;
            case '#':
                H[1] = n;
                break;
            case '$':
                H[2] = n;
                break;
            case '%':
                H[3] = n;
                break;
            case '&':
                H[4] = n;
                break;
            case '*':
                H[5] = n;
                break;
            case '@':
                H[6] = n;
                break;
            case '^':
                H[7] = n;
                break;
            case '~':
                H[8] = n;
                break;
            default:
                break;
            }
        }

        for (auto &c : H)
            cout << c << ' ';
        cout << endl;
    }
    return 0;
}
