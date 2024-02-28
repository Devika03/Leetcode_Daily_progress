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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        int leftTree=root->val;
        q.push({root,0});
        int prevlvl=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int lvl=it.second;
            if(prevlvl!=lvl){
                leftTree=node->val;
                prevlvl=lvl;
            }
            if(node->left){
                q.push({node->left,lvl+1});
            }
            if(node->right){
                q.push({node->right,lvl+1});
            }
        }
        return leftTree;
        
    }
};