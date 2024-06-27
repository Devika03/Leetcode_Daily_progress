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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
       
        vector<vector<int>>ans;
        
        if(root==NULL) return ans;
        
        
        queue<TreeNode*>q;
        q.push(root);
        
        int flag=1;//Current will be L to R ,next change to 0 to indicate R to L .
        
        while(!q.empty())
        {

            int size=q.size();//stores the size of queue
            vector<int>temp(size);//temp vector stores the all nodes value of particular level 
            
            for(int i=0;i<size;i++)
            {
                //i=0 to size
                //storing the front most element of queue in node
                TreeNode*node=q.front();
                //popping the front elemenet in queue
                q.pop();

                if(flag==1)
                {
                    //then store left to right
                   temp[i]=node->val;
                }else{
                    //if flag==0 then store right to left
                    temp[size-i-1]=node->val;
                }
                //pushing the left and right of nodes 
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            
            flag=!flag;
            
            ans.push_back(temp);
        }
        return ans;
    }
};