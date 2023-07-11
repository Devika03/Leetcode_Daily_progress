/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> Dijkstra(vector<int> adj[],int target,int k)
    {
        queue<pair<int,int> > q;
        q.push({0,target});
        vector<int> dis(501,1e9);
        dis[target]=0;
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();

            for(auto it : adj[x.second])
            {
                if(dis[it]==1e9)
                {
                    dis[it]=dis[x.second]+1;
                    q.push({dis[it],it});
                }
            }
        }
        vector<int> res;
        int i;
        for(i=0; i<501; i++)
        {
            if(dis[i]==k)
             res.push_back(i);
        }
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> adj[501];
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
           auto x=q.front();
           int value=x->val;
           q.pop();

           if(x->left)
           {
               adj[value].push_back(x->left->val);
               adj[x->left->val].push_back(value);
               q.push(x->left);
           }
           if(x->right)
           {
               adj[value].push_back(x->right->val);
               adj[x->right->val].push_back(value);
               q.push(x->right);
           }
        }
        return Dijkstra(adj,target->val,k);
    }
};