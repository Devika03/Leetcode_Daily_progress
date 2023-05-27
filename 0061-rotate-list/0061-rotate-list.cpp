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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next || k==0)return head;
        
        ListNode * i = head;
        int len = 1 ; // To calc. the length.  
        while(i->next && ++len)
        {
            i=i->next;
        }
        i->next=head;
        k=k%len;//if k>=len 
        k=len-k;// To findlen-k th node from start.
        while(k--) i= i->next;
        
        head = i->next;
        i->next=NULL;
        
        return head;
    }
};