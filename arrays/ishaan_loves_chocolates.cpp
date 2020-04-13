#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;
        int arr[n]{0};
        int min{static_cast<int>(INFINITY)};
        for (auto &a : arr)
        {
            cin >> a;
            if (a < min)
                min = a;
        }
        cout << min << endl;
    }
    return 0;
}