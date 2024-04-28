class Solution {
    int dfs(int node, int prev, int dist, vector<vector<int>> &adj,
     vector<pair<int,int>> &dist_node){
        
        int cnt=0;
        for(auto &it: adj[node]){
            if(it!=prev){
                cnt+=dfs(it, node, dist+1, adj, dist_node);
            }
        }

        dist_node[node]=make_pair(dist, cnt);

        return cnt+1;
    }

    void solve(int node, int prev, int prev_dist, vector<vector<int>> &adj,
    vector<pair<int,int>> &dist_node, vector<int> &ans){
        int n=ans.size();
        for(auto &it: adj[node]){
            if(it!=prev){
                int num_of_nodes=dist_node[it].second;
                int inc=n-2-num_of_nodes;
                int dec=num_of_nodes;
                ans[it]=prev_dist+inc-dec;
                solve(it, node, ans[it],adj, dist_node, ans);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> dist_node(n);
        vector<vector<int>> adj(n);

        for(auto &it: edges){
            int u=it[0], v=it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        dfs(0, -1, 0, adj, dist_node);

        int dist_zero=0;
        vector<int> ans(n, 0);
        for(auto &it: dist_node){
            dist_zero+=it.first;
        }
        ans[0]=dist_zero;

        solve(0, -1, dist_zero, adj, dist_node, ans);

        return ans;
    }
};