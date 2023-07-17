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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextNode= curr;
        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr=nextNode;
        }
        head->next=NULL;
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2= reverseList(l2);
        ListNode* newHead=NULL;
        ListNode* newTail = NULL;
        int carry = 0 ;
        while(l1!=NULL && l2!=NULL){
            int sum = carry + l1->val + l2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            if(newHead==NULL){
                newHead = newNode ;
                newTail = newNode;
            }else{
                newTail->next =newNode;
                newTail = newNode;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int sum = carry + l1->val;
            ListNode* newNode = new ListNode(sum%10);
            newTail->next =newNode;
            carry = sum/10;
            newTail = newNode;
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum = carry+l2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            newTail->next = newNode;
            newTail = newNode;
            l2=l2->next;
        }
        while(carry!=0){
            ListNode* newNode = new ListNode(carry%10);
            carry=carry/10;
            newTail->next = newNode;
            newTail  = newNode;
        }
        return reverseList(newHead);
    }
};