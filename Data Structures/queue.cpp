#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v)
    {
        this->val = v;
        next=NULL;
    }
};
// queue
Node* enqueue(Node* head, int val)
{
    Node* ptr = new Node(val);
    if(!head)
        return head = ptr;
    Node* temp = head;
    while(temp->next)
        temp=temp->next;
    temp->next = ptr;
    return head;
}
Node* dequeue(Node* head)
{
    if(!head)
        return head;
    head=head->next;
    return head;
}
// circular queue
struct CircularQueue
{
    Node* head;
    Node* tail;
    // CircularQueue(int val)
    // {
    //     head = new Node(val);
    //     tail = head;
    // }

    Node* enQueue(int val)
    {
        Node* temp = new Node(val);
        if(head){
            tail->next = temp;
            tail = temp;
        }
        else
            head=tail=temp;
        tail->next = head;
        return head;
    }

    Node* deQueue()
    {
        if(head==tail)
            return head=tail=NULL;
        tail->next = head->next;
        head=tail->next;
        return head;
    }
    void print()
    {
        Node* ptr = head;
        while(ptr->next!=head)
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<ptr->val<<" ";
        cout<<endl;
    }

};
int main()
{
    Node* head = NULL;
    for(int i=1;i<=5;i++)
        head = enqueue(head, i);
    // print queue
    cout<<"Queue\n";
    Node* ptr = head;
    while(ptr)
    {
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<endl;

    // circular queue
    CircularQueue cq;
    for(int i=0;i<=5;i++)
    {
        cq.enQueue(i);
    }
    cq.deQueue();
    cout<<"Circular Queue after deletion:\n";
    cq.print();
    return 0;
}