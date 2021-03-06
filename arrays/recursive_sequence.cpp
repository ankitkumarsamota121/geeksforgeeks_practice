#include <bits/stdc++.h>
using namespace std;

#define FOREACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()

#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define F first
#define S second
#define mk make_pair
#define mod 1000000007 // 10e9 + 7

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

ll mpow(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res % mod;
}

ll func(ll n){
    ll t = 1;
    ll num = 1;
    ll res = 0;
    ll temp;
    while (1){
        temp = 1;
        FOR(i, 0, t){
            temp *= num;
            num++;
        }
        res += temp;
        if (n == t)
            return res;
        t++;
    }
}

ll rfunc(ll s, ll t, ll n){
    if (t == n+1)
        return 0;
    ll temp = 1;
    FOR(i, 0, t) temp *= s++;
    return temp + rfunc(s, t + 1, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << rfunc(1, 1, n) << endl;

    }
    return 0;
}