#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* next;
    int val;
    Node(int a)
    {
        next=NULL;
        val = a;
    }
};
Node* addOne(Node* head)
{
    Node* last = NULL;
    Node* cur = head;
    while(cur->next)
    {
        if(cur->val!=9)
        {
            last = cur;
        }
        cur = cur->next;
    }  

    if(cur->val!=9)
    {
        cur->val++;
        return head;
    }

    if(!last)
    {
        last = new Node(0);
        last->next = head;
        head = last;   
    }

    last->val++;
    last = last->next;

    while(last)
    {
        last->val = 0;
        last=last->next;
    }

    return head;
}
void print(Node* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
}
int main()
{

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
 
    cout << "Original list is : ";
    print(head);
 
    head = addOne(head);
 
    cout << "Resultant list is : ";
    print(head);
 
    return 0;
}