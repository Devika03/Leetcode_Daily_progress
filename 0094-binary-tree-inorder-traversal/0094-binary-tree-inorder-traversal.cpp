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
    void inorder(TreeNode* root,vector<int>& v) 
    {
        if(root==NULL)//If Leaf Node. 
            return ;
        
         inorder(root->left,v);//L
         v.push_back(root->val);//Root
         inorder(root->right,v);//R
    }
    vector<int> inorderTraversal(TreeNode* root) //To declare v and to return that v. 
    {
        vector<int> v;
        inorder(root,v);
        return v;
    }
};