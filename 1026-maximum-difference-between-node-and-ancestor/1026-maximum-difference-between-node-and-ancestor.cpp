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

    pair<int,int> solve(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return {root->val,root->val};
        }

        
        pair<int,int>l={-1,-1};
        if(root->left)
        l=solve(root->left);
        pair<int,int>r={-1,-1};
        if(root->right)
        r=solve(root->right);

        int v=root->val;
        int ll=INT_MAX,rr=INT_MIN;
        if(root->left){
            ans=max(ans,max(abs(l.first-v),abs(l.second-v)));
            ll=min(v,l.first);
            rr=max(v,l.second);
        }

        if(root->right){
            ans=max(ans,max(abs(r.first-v),abs(r.second-v)));
            ll=min(ll,r.first);
            rr=max(rr,r.second);
        }

        ll=min(ll,v);
        rr=max(rr,v);
        // cout<<v<<" "<<l.first<<" "<<l.second<<" "<<r.first<<" "<<r.second<<" "<<ans<<endl;
        return {ll,rr};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
         solve(root);
         return ans;
    }
};