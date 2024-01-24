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
    int ans=0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        dfs(root,mp,0);
        return ans;
    }
    
    void dfs(TreeNode* root,map<int,int> &mp,int odd){
        if(!root) return;
        mp[root->val]++;
        if(mp[root->val]%2==0)  odd--;
        else odd++;
        dfs(root->left,mp,odd);
        dfs(root->right,mp,odd);
        mp[root->val]--;
        if(!root->left && !root->right && odd<2) ans++;
    }
};