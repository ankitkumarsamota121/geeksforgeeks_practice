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
        for (auto &a : arr)
            cin >> a;
        
        sort(arr, arr+n);

        int max_counts{0};
        int area{};
        int max_area{0};
        int count{0};

        for (int i{0}; i < n; i++)
        {
            count = 0;
            area = arr[i] * arr[i];
            cout << arr[i] << ' ' << area << endl;
            for (int j{i}; j<n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    i++;
                }
            }

            cout << count << endl;
            if (count >= 4 && area > max_area)
            {
                max_area = area;
                max_counts = count;
            }
        }
        if (max_area)
            cout << max_area << ' ' << max_counts/4 << endl;
        else
            cout << -1 << endl;
    }
}