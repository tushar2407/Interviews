#include<bits/stdc++.h>
using namespace std;

// singly linked list
struct Node
{
    int val;
    Node* next;
    Node(int v)
    {
        this->val = v;
        next = NULL;
    }
};
// doubly linked list
struct DoubleNode
{
    int val;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(int v)
    {
        this->val = v;
        next= prev = NULL;
    }
};

// circular queue
// always added at the start of the list
Node* push(Node* head, int data)
{
    Node* ptr = new Node(0);
    Node* temp = head;
    ptr->val = data;
    ptr->next = head;

    if(head)
    {
        while(temp->next != head)
            temp=temp->next;
        temp->next = ptr;
    }
    else
        ptr->next = ptr;
    
    return head = ptr;
}

int main()
{
    // singlyLinked List
    Node* head = new Node(0);
    Node *ptr = head;
    for(int i=1;i<=5;i++)
    {
        Node* temp = new Node(i);
        ptr->next = temp;
        ptr = temp;
    }
    ptr = head;
    cout<<"Single Linked List\n";
    while(ptr)
    {
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<endl;

    DoubleNode* headDouble = new DoubleNode(0);
    DoubleNode *ptrDouble = headDouble;

    for(int i=1;i<=5;i++)
    {
        DoubleNode *temp = new DoubleNode(i);
        ptrDouble->next = temp;
        temp->prev = ptrDouble;
        ptrDouble = temp; 
    }
    ptrDouble = headDouble;
    cout<<"Doubly Linked Lists:\n";
    while(ptrDouble)
    {
        cout<<ptrDouble->val<<" ";
        ptrDouble=ptrDouble->next;
    }
    cout<<endl;


    return 0;
}