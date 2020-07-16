// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// design the class:

class LRUCache {
   private:
    int C;
    deque<int> Q;
    unordered_map<int, int> M;

   public:
    LRUCache(int cap) {
        // constructor for cache
        C = cap;
        Q.clear();
        M.clear();
    }

    int get(int key) {
        // this function should return value corresponding to key
        if (M.count(key) != 0) {
            return M[key];
        }
        return -1;
    }

    void set(int key, int value) {
        // storing key, value pair
        if (Q.size() == C) {
            if (M.count(key) != 0) {
                M[key] = value;
            } else {
                M.erase(Q.front());
                Q.pop_front();
            }
        }
        Q.push_back(key);
        M[key] = value;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends