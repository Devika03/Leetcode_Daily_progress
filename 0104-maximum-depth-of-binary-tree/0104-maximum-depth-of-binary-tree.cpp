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
    void helper(TreeNode* node , vector<vector<int>>&ans)
    {
        if(node==NULL)return;
        
        queue<TreeNode*>q;
        q.push(node);
        
        while(!q.empty())
        {
            vector<int>ans_temp;
            
            int size = q.size(); //To get the size of the current level. 
            for(int i = 0 ; i<size ; i++)
            {
                TreeNode*temp = q.front();
                ans_temp.push_back(temp->val);
                q.pop();
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right !=NULL) q.push(temp->right);
            }
            ans.push_back(ans_temp);
        }
    }
    
    int maxDepth(TreeNode* root) 
    {
        vector<vector<int>>result;
        helper(root,result);
        return result.size();
    }
};