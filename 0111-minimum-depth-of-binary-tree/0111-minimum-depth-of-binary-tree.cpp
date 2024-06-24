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
    int minDepth(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        int depth = 1;
        
        while (!q.empty()) 
        {
            int level_size = q.size(); // Number of nodes at the current level
            
            for (int i = 0; i < level_size; i++ ) 
            {
                TreeNode* node = q.front();
                q.pop();
                
                // Check if this is a leaf node
                if (node->left == NULL && node->right == NULL) 
                {
                    return depth;
                }
                
                // Add the children nodes to the queue
                if (node->left != NULL) 
                {
                    q.push(node->left);
                }
                if (node->right != NULL) 
                {
                    q.push(node->right);
                }
            }
            
            // Increment depth after processing all nodes at the current level
            depth++;
        }
        
        return depth;
    }
};