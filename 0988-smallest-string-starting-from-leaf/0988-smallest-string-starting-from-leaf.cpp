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
    string smallestFromLeaf(TreeNode* root, string s = "") {
        s = ((char) (root -> val + 'a')) + s;
        if(root -> left == nullptr && root -> right == nullptr)
            return s;
        
        if(root -> left == nullptr) return smallestFromLeaf(root -> right, s);
        if(root -> right == nullptr) return smallestFromLeaf(root -> left, s);

        string left = smallestFromLeaf(root -> left, s);
        string right = smallestFromLeaf(root -> right, s);

        return left.compare(right) < 0 ? left : right;
    }
};