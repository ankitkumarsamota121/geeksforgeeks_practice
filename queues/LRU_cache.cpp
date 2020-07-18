// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// design the class:

class LRUCache {
   private:
    map<int, int> mp;
    unordered_map<int, deque<int>::iterator> M;
    deque<int> temp;
    int capacity;

   public:
    LRUCache(int cap) {
        // constructor for cache
        mp.clear();
        temp.clear();
        M.clear();
        capacity = cap;
    }

    int get(int key) {
        // this function should return value corresponding to key
        if (mp.find(key) == mp.end()) {
            return -1;
        } else {
            // deque<int>::iterator itr = M[key];
            // while (*itr != key) itr++;
            temp.erase(M[key]);
            temp.push_front(key);
            M[key] = temp.begin();
            return mp[key];
        }
    }

    void set(int key, int value) {
        // storing key, value pair
        if (mp.find(key) == mp.end()) {
            if (temp.size() == capacity) {
                int k = temp.back();
                temp.pop_back();
                mp.erase(k);
                M.erase(k);
            }
        } else {
            // deque<int>::iterator itr = temp.begin();
            // while (*itr != key) itr++;
            temp.erase(M[key]);
            mp.erase(key);
        }
        temp.push_front(key);
        mp[key] = value;
        M[key] = temp.begin();
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