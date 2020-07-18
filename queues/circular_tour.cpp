// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump[], int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n) << endl;
    }
}
// } Driver Code Ends

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

bool check(petrolPump p[], int n, int start) {
    int petrol = p[start].petrol;
    int distance = p[start].distance;
    if (distance > petrol) {
        return false;
    }
    int i = (start + 1) % n;
    while (i != start) {
        distance += p[i].distance;
        petrol += p[i].petrol;
        if (distance > petrol) {
            return false;
        }

        i = (i + 1) % n;
    }
    return true;
}

/*You are required to complete this method*/
// int tour(petrolPump p[], int n) {
//     //Your code here
//     int i = 0;
//     while (i < n) {
//         // cout << check(p, n, i) << endl;
//         if (check(p, n, i))
//             return i;
//         i++;
//     }
//     return -1;
// }

int tour(petrolPump p[], int n) {
    int start = 0;
    int end = 1;

    int curr_petrol = p[start].petrol - p[start].distance;
    while (end != start || curr_petrol < 0) {
        while (curr_petrol < 0 && start != end) {
            curr_petrol -= p[start].petrol - p[start].distance;
            start = (start + 1) % n;

            if (start == 0)
                return -1;
        }

        curr_petrol += p[end].petrol - p[end].distance;

        end = (end + 1) % n;
    }

    return start;
}