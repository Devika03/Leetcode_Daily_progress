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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (headA == NULL || headB ==NULL) return NULL;//means no intersection. 
        ListNode*d1 = headA;
        ListNode*d2 = headB;
        
        while(d1!=d2)
        {
            d1=d1 ==NULL?headB:d1->next;//If d1=NULL , you shift it to head of l2. 
            d2=d2==NULL?headA:d2->next;//If d2= NULL , you shift it to head of l1.
            
        }
        return d1;//if d1==d2.
            
    }
};