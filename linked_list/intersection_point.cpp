// { Driver Code Starts
#include <stdio.h>

#include <iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size) {
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main() {
    int T, n1, n2, n3;

    cin >> T;
    while (T--) {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2) {
    // Your Code Here
    Node* temp = head1;
    int c1 = 0;
    while (temp) {
        c1++;
        temp = temp->next;
    }

    int c2 = 0;
    temp = head2;
    while (temp) {
        c2++;
        temp = temp->next;
    }

    int ans = -1;

    int t = abs(c1 - c2);

    if (c1 >= c2) {
        while (t--) head1 = head1->next;
    } else {
        while (t--) head2 = head2->next;
    }

    while (head1 and head2) {
        if (head1 == head2) {
            ans = head1->data;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return ans;
}
