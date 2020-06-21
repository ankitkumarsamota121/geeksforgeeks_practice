// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        n = n - 1;
        cin >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

node *getTail(node *curr){
    while(curr != NULL && curr->next != NULL)
        curr = curr->next;
    return curr;
}

node *partition(node *head, node *end, node **newHead, node **newEnd){
    node *pivot = end;
    node *prev = NULL, *cur = head, *tail = pivot;

    while(cur != pivot){
        if (cur->data < pivot->data){
            if ((*newHead) == NULL) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else{
            if (prev) prev->next = cur->next;
            node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL) (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

node *quickSortRecur(node *head, node *end){
    if (!head || head == end) return head;

    node *newHead = NULL, *newEnd = NULL;

    node *pivot = partition(head, end, &newHead, &newEnd);
    
    if (newHead != pivot){
        node *tmp = newHead;
        while(tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}