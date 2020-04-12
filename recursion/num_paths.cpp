#include <bits/stdc++.h>
using namespace std;

int numPaths(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    return numPaths(m-1, n) + numPaths(m, n-1);
}

int main()
{
    int t{};
    int n{};
    int m{};
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        cout << numPaths(m, n) << endl;
    }    
    return 0;
}