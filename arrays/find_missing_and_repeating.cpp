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
        int H[n+1]{0};
        int a{};
        for(int i{0}; i<n; i++)
        {
            cin >> a;
            H[a]++;
        }

        int repeating{};
        int missing{1000000};

        for(int i{ 1 }; i <= n; i++)
        {
            if (H[i] == 0 && H[i] < missing)
                missing = i;
            
            if (H[i] > 1)
                repeating = i;
        }

        cout << repeating << ' ' << missing << endl;
    }
    return 0;
}