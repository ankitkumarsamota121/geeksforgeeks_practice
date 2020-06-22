#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

   public:
    MinHeap(int a[], int size);
    void MinHeapify(int i);
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return (2 * i + 1);
    }
    int right(int i) {
        return (2 * i + 2);
    }

    int extractMin();
    int getMin() {
        return harr[0];
    }
};

MinHeap::MinHeap(int a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin() {
    if (heap_size == 0) {
        return INT_MAX;
    }

    int root = harr[0];

    if (heap_size > 1) {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
    heap_size--;
    return root;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size and harr[l] < harr[i]) {
        smallest = l;
    }
    if (r < heap_size and harr[r] < harr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

void a_k_s() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

int main() {
    a_k_s();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        MinHeap mh(a, n);

        cin >> k;
        for (int i = 0; i < k - 1; i++) {
            mh.extractMin();
        }

        cout << mh.getMin() << endl;
    }

    return 0;
}