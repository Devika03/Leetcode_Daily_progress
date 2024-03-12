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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* curr=head;
        ListNode *prev=NULL;
           
           while(curr!=NULL){
                 
                 ListNode *temp=curr;
                  int sum=0;
                   int f=0;
                  while(curr!=NULL){
                    sum=sum+curr->val;
                    if(sum==0){
                        f=1;
                        if(prev==NULL){
                            prev=NULL;
                            head=curr->next;
                            curr=curr->next;
                        }else{
                            prev->next=curr->next;
                            curr=curr->next;
                        }

                        break;
                    }else{
                        curr=curr->next;
                    }
                  }

                    if(f==0){
                        prev=temp;
                        curr=temp->next;
                    }
           }

return head;
    }
};