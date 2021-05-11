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
class Solution {
public:
    //1. find the middle element for merge sort
    ListNode* middle(ListNode* node)
    {
        if(node==NULL || node->next==NULL)
        {
            return NULL;
        }
        ListNode* slow = node;
        ListNode* fast = node;
        while( fast->next!=NULL && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    // 2. Merge two sorted linked list
    // this step is used for merging all the list back
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->val<t2->val)
            {
                curr->next = t1;
                t1=t1->next;
            }
            else
            {
                curr->next = t2;
                t2=t2->next;
            }
            curr=curr->next;
        }
        if(t1!=NULL)
        {
            curr->next = t1;
        }
        if(t2!=NULL)
        {
            curr->next=t2;
        }
        
        return dummy->next;
    }
    
    // 3. last and most important step
    ListNode* sortList(ListNode* head) {
        // this is question is same as merge sort
        // have few steps to follow
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        // we call for our mid value
        ListNode* mid = middle(head);
        ListNode* new_head = mid->next;
        mid->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(new_head);
        
        return merge(l1,l2);
        
    }
};
