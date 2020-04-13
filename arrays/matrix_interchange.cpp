#include <iostream>
using namespace std;

int arr[1000][1000];

void interchange(int r, int c)
{
    for (int i{0}; i < r; i++)
    {
        swap(arr[i][0], arr[i][c-1]);
    }
    

    //Printing the modified matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> arr[i][j];

        interchange(r, c);
    }
    return 0;
}