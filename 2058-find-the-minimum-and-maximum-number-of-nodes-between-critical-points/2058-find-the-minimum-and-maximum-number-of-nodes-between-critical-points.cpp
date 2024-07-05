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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevval=0;
        int currval=0;
        int nextval=0;

        int mindist=INT_MAX;
        int firstcriticalposition=0;
        int prevcriticalposition=0;

        int i=0;
        vector<int>result={-1,-1};
        while(head!=NULL){
            prevval=currval;
            currval=nextval;
            nextval=head->val;

            if(prevval!=0 && currval!=0 && nextval!=0 && ((prevval>currval && currval <nextval)|| (prevval<currval && currval>nextval))) {
                if(firstcriticalposition==0){
                    firstcriticalposition=i;

                }else{
                    mindist=min(mindist,i-prevcriticalposition);
                    result={mindist,i-firstcriticalposition};
                }
                prevcriticalposition=i;

            }
            i++;
            head=head->next;




        }
        return result;
    }
};