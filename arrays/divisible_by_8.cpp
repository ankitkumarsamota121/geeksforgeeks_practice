#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--)
    {
        string n{};
        getline(cin, n);
        string last_three{};

        if (n.length() < 3)
            last_three = n;
        else
            last_three = n.substr(n.length()-3, 3);

        int num { stoi(last_three) };
        if (num%8)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}