#include<bits/stdc++.h>
using namespace std;

ListNode* reverse(ListNode* head)
{
    ListNode* current = head;
    ListNode* prev, *next;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev=currentl
        current = next;
    }
    return head=prev;
}