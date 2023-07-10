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
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        if(!root->left) return 1+helper(root->right);
        else if(!root->right) return 1+helper(root->left);
        return min(helper(root->left),helper(root->right))+1;
    }
public:
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};