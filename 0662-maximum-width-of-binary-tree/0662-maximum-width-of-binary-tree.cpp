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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int width = INT_MIN;
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            
            TreeNode* temp_node=q.front().first;
            int index = q.front().second;
            
            int min= q.front().second;
            
            int first , last; //width = last-first+1
            
            for(int i=0;i<size;i++)
            {
                int res = q.front().second - min;
                
                TreeNode* node=q.front().first;
                q.pop();
                
                if(i==0)first=res;
                if(i==size-1)last=res;

                if(node->left){
                    q.push({node->left,(long long)2*res+1});
                }
                if(node->right){
                    q.push({node->right,(long long)2*res+2});
                }
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};