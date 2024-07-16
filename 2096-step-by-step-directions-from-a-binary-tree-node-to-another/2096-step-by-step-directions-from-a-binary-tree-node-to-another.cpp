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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        // Find paths from root to start and destination nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        string directions;
        int commonPathLength = 0;

        // Find the length of the common path
        while (commonPathLength < startPath.length() &&
               commonPathLength < destPath.length() &&
               startPath[commonPathLength] == destPath[commonPathLength]) {
            commonPathLength++;
        }

        // Add "U" for each step to go up from start to common ancestor
        for (int i = 0; i < startPath.length() - commonPathLength; i++) {
            directions += "U";
        }

        // Add directions from common ancestor to destination
        for (int i = commonPathLength; i < destPath.length(); i++) {
            directions += destPath[i];
        }

        return directions;
    }

private:
    bool findPath(TreeNode* node, int target, string& path) {
        if (node == nullptr) {
            return false;
        }

        bool find = false;

        if (node->val == target) {
            find = true;
        }
        
        if (!find) {
            // Try left subtree
            path += "L";
        }
        if (findPath(node->left, target, path)) {
            find = true;
        }       
        if (!find) {
            path.pop_back();  // Remove last character
        }

        if (!find) {
            // Try right subtree
            path += "R";    
        }
        if (findPath(node->right, target, path)) {
            find = true;
        }
        if (!find) {
            path.pop_back();  // Remove last character
        }

        return find;
    }
};