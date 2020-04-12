#include <iostream>
using namespace std;

static int m{0};

void move_plates(int n, int A, int B, int C, int k)
{
    if (n > 0)
    {
        move_plates(n-1, A, C, B, k);
        m++;
        if (m == k)
        {
            cout << A << ' ' << C << '\n';
            return;
        }
        move_plates(n-1, B, A, C, k);
    }
}

int main()
{
    int t{};
    int n{};
    int k{};
    cin >> t;
    while(t--)
    {
        m = 0;
        cin >> n >> k;
        move_plates(n, 1, 2, 3, k);
    }
}