#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--)
    {
        string A[]{"0", "2", "22", "222", "3", "33", "333", "4", "44", "444",
                   "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777",
                   "8", "88", "888", "9", "99", "999", "9999"};
        string str{};
        getline(cin, str);

        string out{};

        for(auto &a : str)
        {
            if (a == ' ')
                out += A[0];
            else
                out += A[static_cast<int>(a) - 64];
        }

        cout << out << endl;
    }
    return 0;
}