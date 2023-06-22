class Solution
{
    vector<int> rightSideView(TreeNode * root)
    {
        vector<int> res;
        recursion(root,0,ds);
        return res;
    }
public:
void recursion(TreeNode*root, int level , vector<int>&ds)
{
    if(root==NULL)return;
    if(level == ds.size())ds.push_back(root->val);
    recursion(root->right , level+1 , ds);
    recursion(root->left , level +1 , ds)

}
}