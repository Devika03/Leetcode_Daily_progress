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
// calculate the length of linked list
    int length_list(ListNode * head, int val){
        if(head==NULL) return val;
        return length_list(head->next,val+1);        
    }
    // Split the list according to the calculate length
    ListNode* splitList(ListNode*head, int len){
        ListNode * temp = head;
        len--; // reduce the length by 1 because we have to make next equal to NULL
        while(len--) temp = temp->next;
            
        ListNode *nexthead= temp->next;
        temp->next = NULL;
        return nexthead;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> vec(k,NULL); // vector store the head of all splited list 
        int len = length_list(head,0); // length of linked list
        int temp_len = len/k; // minimum length of each splited list
        int rem = len%k; // some node are remain we increase the length of possible splited list
        vector<int>each_len(k,temp_len);
        int i=0;
        while(rem--){
            each_len[i++]++;
        }

        vec[0] = head;
        for(int j=1;j<k;j++){
            if(each_len[j]>0){
                vec[j] = splitList(vec[j-1],each_len[j-1]);
            }
        }
        return vec;        
    }
};