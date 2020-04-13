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
        int arr[n];
        int count[n];
        int c{0};
        for (auto &a : arr)
            cin >> a;

        for (int i{0}; i<n; i++)
        {
            c = 0;
            for (int j{i}; j<n; j++)
            {
                if (arr[i] > arr[j])
                    c++;
            }
            count[i] = c;
        }
        
        for (auto &a : count)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}