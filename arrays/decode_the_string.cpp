#include <bits/stdc++.h>
using namespace std;

#define FOREACH(i, c) for (auto &i : c)
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        string temp{};
        string temp_;
        string num;
        string ans{};
        FOREACH(c, s){
            if (c == ']'){
                temp = "";
                while (st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string temp_ = temp;
                string num = "";
                while (!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    num = st.top() + num;
                    st.pop();
                }
                FOR(i, 1, stoi(num)) temp += temp_;
                FOREACH(t, temp) st.push(t);
            }
            else
                st.push(c);
        }

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        cout << ans << endl;
    }

    return 0;
}