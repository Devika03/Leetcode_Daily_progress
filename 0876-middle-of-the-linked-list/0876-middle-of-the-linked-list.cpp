//Middle of LL is always @ 1/2th location .  
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next!=NULL)// For 0 Node and 1 Node. 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};