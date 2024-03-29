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
    bool isPalindrome(ListNode* head) 
    {
        stack<int>s;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
         if (fast != NULL) {
            slow = slow->next;
        }
        while(slow!=NULL)
        {
            if(s.top()!=slow->val)
                return false;
            else
            {
                s.pop();
                slow=slow->next;
            }
        }
        if(s.empty())
            return true ; 
        return false;
        
        
    }
};
/*
if(head==NULL || head->next == NULL) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast->next!=NULL &&fast->next->next !=NULL)//Odd / Even case [ Middle of ll]
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = reverseList(slow->next); 
        slow=slow->next;//Pting. to first node of right half.
        
        while(slow!=NULL)
        {
            if(head->val !=slow->val)return false;//Not pld
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode*head)
    {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next = pre;
            pre=head;
            head=next;
        }
        return pre;
*/