#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        int d{};
        cin >> n >> d;
        vector<int> array(n);
        for (int &num : array)
            cin >> num;

        reverse(array.begin(), array.end());
        reverse(array.begin(), (array.end() - d));
        reverse(array.begin() + (n - d), array.end());

        for (int &num : array)
            cout << num << ' ';

        cout << '\n';
    }
    return 0;
}