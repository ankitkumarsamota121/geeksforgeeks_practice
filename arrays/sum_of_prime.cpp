#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for(int i{2}; i<=sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;

        bool flag{false};

        for (int i{2}; i <= n/2; i++)
        {
            if (isPrime(i) && isPrime(n-i))
            {
                flag = true;
                cout << i << ' ' << n-i << endl;
                break;
            }
        }
        if(!flag)
            cout << -1 << endl;
    }
    return 0;
}