/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL|| head->next == NULL) return NULL ;
        ListNode*slow=head;
        ListNode*fast=head;
        bool hasCycle = false; 
        while(fast!=NULL && fast->next!=NULL)// It should be &&
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) 
            {
                hasCycle=true;
                break;
            }
        }
        //After fast has reached the end of LL . 
        if(hasCycle==false) return NULL;
        
        //Deploy the logic of slow=fast. 
        slow = head;
        while (slow != fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};