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
    int prev{};
    void help(TreeNode*root, int&ans){
        if(!root) return ;
        help(root->left,ans);
        if(abs(root->val - prev) < ans){
            ans = abs(root->val - prev);
        }
        prev = root->val;
        help(root->right,ans);
        return ;
    }
    int getMinimumDifference(TreeNode* root){
        int ans = INT_MAX;
        prev = INT_MAX;
        help(root, ans);
        return ans;
    }

};