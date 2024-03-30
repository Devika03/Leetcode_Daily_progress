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
/*
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == NULL || head->next == NULL || k == 0) return head;
        ListNode*l=head;
        int len = 0; 
        while(l!=NULL)
        {
            len++;
            l=l->next;
        }
        k = k % len;
        int index = len - k - 1 ;
        ListNode*temp = head;
        for(int i = 1 ; i<=index ; i++)
        {
            temp=temp->next;
        }
        ListNode*dummy=temp;
        while(dummy->next->next!=NULL)
        {
            dummy=dummy->next;
        }
        ListNode*new_head = dummy;
        dummy = dummy->next;
        dummy ->next = head;
        temp->next = NULL; 
        return new_head;
    }
};*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        // Calculate the length of the list
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        
        // Adjust k to avoid unnecessary rotations
        k = k % len; // Effective k if k = 4 and len = 3 , [0,1,2]
        if (k == 0) return head; // No rotation needed
        
        // Find the new head position
        int newHeadIndex = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < newHeadIndex; i++) {
            newTail = newTail->next;
        }
        
        // Perform the rotation
        tail->next = head;
        head = newTail->next; // New head 
        newTail->next = NULL; 
        
        return head;
    }
};