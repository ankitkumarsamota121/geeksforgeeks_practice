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
        int arr[n];
        for (auto &a : arr)
            cin >> a;
        sort(arr, arr+n);
        int count{1};
        int maj_element{-1};
        int i{ 0 };
        while (i<n)
        {
            while(arr[i] == arr[i+1])
            {
                i++;
                count++;
            }
            // cout << count << endl;
            if (count > n/2)
                maj_element = arr[i];
            if (arr[i] != arr[i+1])
            {
                i++;
                count = 1;
            }
        }
        cout << maj_element << endl;
    }
    return 0;
}