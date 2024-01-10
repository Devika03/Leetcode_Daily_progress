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
    void solve(TreeNode* root,vector<vector<int>>&dp){
        //base case
        if(!root)return;
        if(root->left){
            dp[root->val].push_back(root->left->val);
            dp[root->left->val].push_back(root->val);
        }
        if(root->right){
            dp[root->val].push_back(root->right->val);
            dp[root->right->val].push_back(root->val);
        }
        solve(root->left,dp);
        solve(root->right,dp);
    }
    int bfs(int start,vector<vector<int>>dp,set<int>&st){
        list<vector<int>> q;
        int cnt = 0;
        q.push_back({start});
        st.insert(start);
        // while(!q.empty()){
        //     int a = q.front();
        //     q.pop_front();
        //     bool flag = true;
        //     for(auto it:dp[a]){
        //         if(it==-1){break;}
        //         else if(st.find(it)==st.end()){st.insert(it);q.push_back(it);if(flag ==true){cnt++;flag = false;}}
        //         else{}
        //     }
        // }
        while(!q.empty()){
            vector<int> a = q.front();
            for(auto it:a){
                cout<<it<< " ";
            }
            cout<<endl;
            cnt++;
            q.pop_front();
            vector<int> ans;
            for(int i=0;i<a.size();i++){
                for(auto it:dp[a[i]]){
                    if(st.find(it)==st.end()){st.insert(it);ans.push_back(it);}
                    else{}
                }
            }
            if(!ans.empty())
                    q.push_back(ans);
        }
        return cnt-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> dp(1e5+1,vector<int>(1-1));
        solve(root,dp);
        set<int> st;
        int a = bfs(start,dp,st);
        return a;
    }
};