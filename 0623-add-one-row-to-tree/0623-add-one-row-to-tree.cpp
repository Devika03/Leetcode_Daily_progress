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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){ // if new node is to be added at first make it first and add the root below it
            TreeNode *newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }

        int curr = 1; // take helper function for recursion solution
        return helper(root, val, depth, curr);
    }

    TreeNode* helper(TreeNode *root, int val, int depth, int curr){
        if(!root) return NULL; // if null return 

        if(depth - 1  == curr){ // if position found to be inserted
            TreeNode *tempLeft = root -> left; // add left node of current one to temp 
            TreeNode *tempRight = root -> right; // similarly add the right one to temp

            root -> left = new TreeNode(val); // add the row nodes
            root -> right = new TreeNode(val);

            root -> left -> left = tempLeft; // add the saved nodes below the row
            root -> right -> right = tempRight;

            return root; // finally return new tree
        }

        // otherwise recursively move forward and continue
        root -> left = helper(root -> left, val, depth, curr + 1);
        root -> right = helper(root -> right, val, depth, curr + 1);
        return root;
    }
};