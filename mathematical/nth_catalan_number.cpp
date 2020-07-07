#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

#define ull unsigned long long

cpp_int binomialCoeff(cpp_int n, cpp_int k) {
    cpp_int res = 1;

    if (k > n - k) {
        k = n - k;
    }

    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

cpp_int catalan(cpp_int n) {
    cpp_int c = binomialCoeff(2 * n, n);
    return c / (n + 1);
}

int main() {
    cpp_int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << catalan(n) << endl;
    }
    return 0;
}