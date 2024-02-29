/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool isEven = true;

        while(!q.empty()){
            int n = q.size();
            int prev = isEven ? INT_MIN : INT_MAX;
            for(int i = 0; i < n; i++){
                TreeNode* currNode = q.front();
                q.pop();
                int curr = currNode->val;

                if(isEven && (prev >= curr || curr % 2 == 0)) return false;
                if(!isEven && (prev <= curr || curr % 2 != 0)) return false;

                prev = curr;

                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }

            isEven = !isEven;
        }

        return true;
    }
};