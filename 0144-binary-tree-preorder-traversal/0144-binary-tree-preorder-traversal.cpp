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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        //root>>left>>right
        vector<int>preorder;
        stack<TreeNode*>st;
        if(root==NULL)return preorder;
        st.push(root);
        while(!st.empty()){ 
            root=st.top();
            st.pop();
            preorder.push_back(root->val);

            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};
/*
class Solution {
public:
    void preorder(TreeNode* root,vector<int>& v) 
    {
        if(root==NULL)//If Leaf Node. 
            return ;
        
         v.push_back(root->val);//Root
         inorder(root->left,v);//L
         inorder(root->right,v);//R
    }
    vector<int> inorderTraversal(TreeNode* root) //To declare v and to return that v. 
    {
        vector<int> v;
        inorder(root,v);
        return v;
    }
};
*/