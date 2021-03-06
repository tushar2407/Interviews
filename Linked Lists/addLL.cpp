// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    // cout<<val<<endl;
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    // printList(head);
    return head;
}

class Solution
{
    public:
    void print(Node* n)
    {
        while(n)
        {
            cout<< n->data << " ";
            n = n->next;
        }
        cout<< endl;
    }

    struct Node* reverse(struct Node* head)
    {
        Node* current = head;
        Node* prev=NULL, *next=NULL;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev=current;
            current = next;
        }
        return head=prev;
        
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {

        int carry = 0;
        struct Node* ptrf = reverse(first), *ptrs = reverse(second);
        struct Node* ans = NULL;
        struct Node* ptr = ans;
        while(ptrf && ptrs)
        {
            int r = ptrf->data+ptrs->data+carry;
            if(!ans)
            {
                ans = new Node(r%10);
                ptr = ans;
            }
            else
            {
                ptr->next = new Node(r%10);
                ptr = ptr->next;
            }
            carry = r/10;
            ptrf = ptrf->next;
            ptrs = ptrs->next;
        }
        while(ptrf)
        {
            int r = ptrf->data+carry;
            ptr->next = new Node(r%10);
            carry = r/10;
            ptr = ptr->next;
            ptrf = ptrf->next;
        }
        while(ptrs)
        {
            int r = ptrs->data+carry;
            ptr->next = new Node(r%10);
            carry = r/10;
            ptr = ptr->next;
            ptrs = ptrs->next;
        }
        if(carry)
        {
            ptr->next = new Node(carry%10);
        }
        return reverse(ans);
        
    }
};


// { Driver Code Starts.

int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends