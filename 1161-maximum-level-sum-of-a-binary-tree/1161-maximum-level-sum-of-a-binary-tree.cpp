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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;  
        int ans = 0;    
        long long int maxSum = LLONG_MIN;   
        long long int sum = 0;
        while (!q.empty()){
            int size = q.size();
            level++;
            sum = 0;
            for (int i = 0; i<size; i++){
                root = q.front();
                q.pop();
                sum += root->val;
                if (root->left!=NULL) q.push(root->left);
                if (root->right!=NULL) q.push(root->right);
            }
            if (sum>maxSum){
                maxSum = sum;
                ans = level;
            }
        }
        return ans;
    }
};