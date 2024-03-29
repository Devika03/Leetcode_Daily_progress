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

class Solution
{
public:
    
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
        {
          if(l1==NULL)return l2;
          if(l2==NULL)return l1;
          ListNode*temp=new ListNode(0);
          ListNode*dummy=temp;  
          while(l1!=NULL && l2!=NULL)
          {
              if(l1->val<=l2->val)
              {
                  temp->next=l1;
                  l1=l1->next;
              }
              else{
              temp->next = l2;
              l2=l2->next;
              }
              temp=temp->next;
          }
            if(l1==NULL)
            {
                while(l2!=NULL)
                {
                temp->next= l2;
                temp=temp->next;
                l2=l2->next;
                }
            }
            if(l2==NULL)
            {
                while(l1!=NULL)
                {
                    temp->next=l1;
                    temp=temp->next;
                    l1=l1->next;
                }
            }
           return dummy->next;
            
        }
};
/* if(l1==NULL) return l2;
            if(l2==NULL) return l1;
            if(l1->val > l2->val) std::swap(l1,l2);//This is done to ensure that l1 always starts with the smaller value.
            ListNode*res=l1;//if(l1->val < l2->val) ; res is a copy of l1 and it'll be final ans. 
            while(l1 != NULL && l2 !=NULL)
            {
                ListNode*temp = NULL ; 
                while(l1 !=NULL && l1->val <=l2->val)//Refer notes : Keep l1++ till l1<l2.
                {
                    temp = l1;
                    l1=l1->next;
                }
                temp->next = l2;
                std::swap(l1,l2);
                
            }
            return res;
            */