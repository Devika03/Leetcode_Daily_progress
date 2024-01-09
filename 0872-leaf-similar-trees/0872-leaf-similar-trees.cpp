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

    //simple depth-first searth appraoch
    void dfs(TreeNode* node , vector<int>& leaf) {

        if (node == NULL)
            return;

        //condition for leaf node as leaf nodes does not have any children.
        if (node->right == NULL and node->left == NULL) {
            leaf.push_back(node->val);
            return;
        }
        dfs(node->left , leaf);
        dfs(node->right , leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> s1 ,s2;
        //s1 and s2 stores the leaf nodes in vectors.
        dfs(root1,s1);
        dfs(root2,s2);


        return s1 == s2;
    }
};