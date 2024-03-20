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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
        
        ListNode* curr = list1;
        for (int i = 1; i < a; i++) 
            curr = curr->next;
        ListNode* lastNode = curr->next;
        for (int i = a; i <= b; i++) 
            lastNode = lastNode->next;

        curr->next = list2;
        ListNode* nxt = list2, *prv = NULL;
        while (nxt) {
            prv = nxt;
            nxt = nxt->next;
        }
        prv->next = lastNode;

        return list1;
    }
};