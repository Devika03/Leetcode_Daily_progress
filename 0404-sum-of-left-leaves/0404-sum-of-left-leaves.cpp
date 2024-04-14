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
    int sum;

    void help(TreeNode  *root,bool side){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && side==true){
            sum+=root->val;
        }

        help(root->left,true);
        help(root->right,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        help(root,false);
        return sum;
    }
};