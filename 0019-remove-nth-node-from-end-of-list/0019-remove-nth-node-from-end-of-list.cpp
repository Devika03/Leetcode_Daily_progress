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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ind = 1;
        ListNode* temp = head;
        
        // Calculate the length of the list
        while (temp != NULL) {
            ind++;
            temp = temp->next;
        }
        
        // Calculate the position of the node to be removed from the beginning
        int pos = ind - n;

        // Handle case when the node to be removed is the head of the list
        if (pos == 1) {
            ListNode* to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }

        // Traverse the list to find the node before the one to be removed
        int count = 1;
        ListNode* d1 = head;
        while (count != pos - 1 && d1 != NULL) {
            d1 = d1->next;
            count++;
        }
        
        // Check if d1->next is not NULL before accessing it
        if (d1 != NULL && d1->next != NULL) {
            ListNode* d2 = d1->next;
            d1->next = d2->next;
            delete d2;
        }
        
        return head;
    }
};

/*class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
          int ind=1;
        ListNode*temp=head;
        ListNode*h=head;
        while(temp!=NULL)
        {
            ind++;
            temp=temp->next;
        }
        int pos = ind - n;
        if (pos == 1) {
            ListNode* to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }
        int count = 1 ; 
        ListNode*d1=head;
        while(count!=pos && d1!=NULL)
        {
            d1=d1->next;
            count++;
        }
        if(d1->next!=NULL)
        {
        d1->val = d1->next->val;
        d1->next = d1->next->next;
        }
        else
        {
          delete d1;  
        }
        return h;
    }
};
*/
/*
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
*/