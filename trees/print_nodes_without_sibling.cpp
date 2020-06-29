// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
Node* buildTree(string str) {
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
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void printSibling(Node* root);

int main() {
    // 	freopen("input.txt","r",stdin);
    // 	freopen("output.txt","w",stdout);

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        // 		string ch;
        // 		getline(cin,ch);
        Node* root = buildTree(s);

        printSibling(root);
        cout << endl;
        // 		cout<<"~\n";
    }
    return 0;
}  // } Driver Code Ends

//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Prints the nodes having no siblings.  */
void printSibling(Node* node) {
    // Your code here
    // Base Case
    if (node == NULL) {
        return;
    }

    bool flag = false;

    vector<int> v;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        if (t->left) {
            q.push(t->left);
            if (!t->right)
                v.push_back(t->left->data);
        }
        if (t->right) {
            q.push(t->right);
            if (!t->left)
                v.push_back(t->right->data);
        }
    }

    sort(v.begin(), v.end());

    if (v.size() == 0) {
        cout << -1;
    } else {
        for (auto x : v) cout << x << ' ';
    }
    return;
}