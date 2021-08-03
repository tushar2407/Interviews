/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(!left) return left;
        if(!right) return right;
        
        ListNode *head=NULL, *curr=NULL, *temp=NULL;
        
        while(left && right)
        {
            if(left->val < right->val){
                temp = left;
                left = left->next;
            }
            else
            {
                temp = right;
                right = right->next;
            }
            temp->next = NULL;
            curr = curr == NULL ? temp :(curr->next=temp);
            if(!head) head = curr;
        }
        
        if(left) curr->next=left;
        if(right) curr->next=right;
        
        return head;
    }
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *prev = NULL, *slow = head, *fast = head;
        do 
        {
            prev = slow;
            slow = slow->next;
            if(fast->next == NULL) break;
            fast = fast->next->next;
        }while(fast);
        prev->next = NULL;
        // cout<<(slow->val)<<" "<<(fast->val)<<endl;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left, right);
    }
};
/*

Sorting A Linked List in O(nlogn) time and O(1) space;

*/