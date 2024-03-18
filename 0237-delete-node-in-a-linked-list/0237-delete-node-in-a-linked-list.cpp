/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
        // Only change node's val , next to that of node->next's. 
    {
        node->val=node->next->val;
        node->next = node->next->next;
    }
};