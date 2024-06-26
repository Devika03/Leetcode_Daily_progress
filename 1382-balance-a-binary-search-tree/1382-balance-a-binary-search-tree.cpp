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
void traverse(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    traverse(root->left, in);

    in.push_back(root->val);

    traverse(root->right, in);
}

TreeNode* construct(vector<int>&in,int s,int e)
{
    if(s>e) return nullptr;

    int mid = s + (e-s)/2;

    TreeNode* left = construct(in,s,mid-1);
    TreeNode* right = construct(in,mid+1,e);

    TreeNode* root = new TreeNode(in[mid]);

    root->left = left ; 
    root->right = right;

    return root;
}



TreeNode *balanceBST(TreeNode *root)
{
    vector<int>in;

    traverse(root, in);

    int n = in.size();
    return construct(in,0,n-1);
}
};