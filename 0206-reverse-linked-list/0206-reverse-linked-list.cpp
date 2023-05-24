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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode*dummy = NULL;
        while(head!=NULL)//Refer notes : We return dummy node if head==NULL
        {
            ListNode*next = head->next; //next is a node who is pointing to head->next as we can't use head->next everywhere.
            head->next = dummy;//We broke the link( 1 - 2 ) and pointed head's next to dummy.  
            dummy = head;//Dummy moves to head. 
            head = next;//head moves to next.
        }
        return dummy;
    }
};