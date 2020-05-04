// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */

void partition(Node *head, Node **p, Node **q){
    Node *f = head;
    Node *s = head;

    while(f->next && f->next->next){
        f = f->next->next;
        s = s->next;
    }

    *p = head;
    *q = s->next;
    s->next = NULL;
}

Node *merge(Node *p, Node *q){
    Node *head = NULL;
    Node *t = head;
    Node *temp = NULL;
    while (p && q){
        if (p->data < q->data){
            temp = new Node(p->data);
            p = p->next;
        }
        else {
            temp = new Node(q->data);
            q = q->next;
        }
        // temp = (p->data < q->data) ? new Node(p->data) : new Node(q->data);
        if (head == NULL){
            head = temp;
            t = head;
        }
        else {
            t->next = temp;
            t = t->next;
        }
    }
    while(p){
        t->next = p;
        p = p->next;
        t = t->next;
    }
    while(q){
        t->next = q;
        q = q->next;
        t = t->next;
    }
    return head;
}


Node *mergeSort(Node *head)
{
    // your code here
    if (head && head->next){
        Node *p, *q;
        partition(head, &p, &q);
        p =  mergeSort(p);
        q = mergeSort(q);
        head = merge(p, q);
    }
    return head;
}

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends