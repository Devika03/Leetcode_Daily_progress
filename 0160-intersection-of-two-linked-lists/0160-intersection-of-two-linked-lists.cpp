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
        // If either list is empty, return null
        if (!headA || !headB) return NULL;
        
        unordered_set<ListNode*> s;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        // Traverse list A and store each node in the set
        while (ptrA!=NULL) {
            s.insert(ptrA);
            ptrA = ptrA->next;
        }
        
        // Traverse list B and check if any node is in the set
        while (ptrB!=NULL) {
            if (s.find(ptrB) != s.end()) {
                // Found intersection point
                return ptrB; 
            }
            ptrB=ptrB->next;

        }
        
        // No intersection found
        return NULL;
    }
};
/*
if (headA == NULL || headB ==NULL) return NULL;//means no intersection. 
        ListNode*d1 = headA;
        ListNode*d2 = headB;
        
        while(d1!=d2)
        {
            d1=d1 ==NULL?headB:d1->next;//If d1=NULL , you shift it to head of l2. 
            d2=d2==NULL?headA:d2->next;//If d2= NULL , you shift it to head of l1.
            
        }
        return d1;//if d1==d2.
            
    */