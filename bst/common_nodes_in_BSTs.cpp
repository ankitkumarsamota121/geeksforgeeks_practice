// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> printCommon(Node *root1, Node *root2);

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        vector<int> res = printCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }

    return 1;
}  // } Driver Code Ends

/*Node structure

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

bool find(Node *root, int x) {
    // Base case
    if (!root) {
        return false;
    }

    // Recursive Case
    if (x == root->data) {
        return true;
    } else if (x < root->data) {
        return find(root->left, x);
    }
    return find(root->right, x);
}

void printCommonUtil(Node *root1, Node *root2, vector<int> &v) {
    if (!root1) {
        return;
    }

    // 1. Check in left subtree
    printCommonUtil(root1->left, root2, v);

    // 2. Check for current node
    bool b = find(root2, root1->data);
    if (b) v.push_back(root1->data);

    // 3. Check in right subtree
    printCommonUtil(root1->right, root2, v);
}

// return a vector containing the intersection of the two BSTs in a sorted order
vector<int> printCommon(Node *root1, Node *root2) {
    //Your code here
    vector<int> ans;

    printCommonUtil(root1, root2, ans);

    return ans;
}
