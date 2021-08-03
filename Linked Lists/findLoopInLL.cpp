#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

int count(Node* head)
{
    int ctr = 1;
    Node* ptr = head->next;
    while(ptr!=head)
    {
        ctr++;
        ptr = ptr->next;
    }
    return ctr;
}

int findLoop(Node* head)
{
    Node* slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
            return count(slow);
    }
    return 0;
}

int main()
{

    struct Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
 
    cout << findLoop(head) << endl;
 
    return 0;
}