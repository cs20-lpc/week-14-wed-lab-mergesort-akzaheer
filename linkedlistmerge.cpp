#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* a, Node* b)
{
    if (a == NULL) return b;            // list a empty, return b
    if (b == NULL) return a;  // list b empty, return a

    Node* result = NULL;

    if (a->data <= b->data)
    {
        result = a;                                         // a is smaller, pick it
        result->next = sortedMerge(a->next, b);  // recurse on rest of a
    }
    else
    {
        result = b;                                     // b is smaller, pick it
        result->next = sortedMerge(a, b->next);      // recurse on rest of b
    }

    return result;  // return merged list head
}

void splitList(Node* source, Node*& front, Node*& back)
{
    Node* slow = source;        // moves 1 step at a time
    Node* fast = source->next; // moves 2 steps at a time

    while (fast != NULL)
    {
        fast = fast->next;              // fast moves 2 steps
        if (fast != NULL)
        {
            slow = slow->next;      // slow moves 1 step
            fast = fast->next;          // fast moves again
        }
    }
    // when fast hits end, slow is at midpoint
    front = source;         // first half starts at head
    back = slow->next;       // second half starts after mid
    slow->next = NULL;          // cut the list in half
}

void mergeSort(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* a;
    Node* b;

    splitList(head, a, b);    // split list into two halves
    mergeSort(a);             // sort first half
    mergeSort(b);             // sort second half
    head = sortedMerge(a, b); // merge both sorted halves
}

int main()
{
    Node* head = NULL;

    int values[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};

    for (int i = 0; i < 10; i++)
        insertEnd(head, values[i]);

    cout << "Before Sorting: ";
    display(head);

    mergeSort(head);

    cout << "After Sorting: ";
    display(head);

    return 0;
}
