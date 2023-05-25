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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode*dummy = new ListNode();//A dummy node with val=0 and next =NULL. 
        dummy->next = head;
        ListNode*fast = dummy ;
        ListNode*slow = dummy ;
        
        for(int i = 1 ; i<=n ; i++) fast= fast->next;
        while(fast->next!=NULL) 
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next = slow->next->next;//if fast->NULL.
        return dummy->next;
        
    }
};