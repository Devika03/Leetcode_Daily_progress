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
    ListNode* ReverseLL(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* nh=ReverseLL(head);
        ListNode* temp=nh;
        ListNode* res=new ListNode(-1);
        ListNode* resh=res;
        int carry=0;
        while(temp){
            int value=temp->val*2+carry;
            carry=value/10;
            ListNode* node=new ListNode(value%10);
            res->next=node;
            res=res->next;
            temp=temp->next;
        }
        if(carry==1){
            ListNode* node=new ListNode(1);
            res->next=node;
        }
        resh=resh->next;
        ListNode* final=ReverseLL(resh);
        return final;
    }
};