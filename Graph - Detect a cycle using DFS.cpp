class Solution{
    private:
    bool dfs(int node ,int parent, vector<int>adj[] , vector<int> vis[])
    {
        vis[node]=1;
        for(auto adjacentnode:adj[node])
        {
            if(!vis[adjacentnode])
            {
                if (dfs(adjacentnode,node , adj,vis )== true) return true;
            }
            else if (adjacentnode!= parent) return True;
        }
        return false;
    }
    public:
    bool isCycle(int V , vector<int> adj[])
    {
        int vis[V]={0};
        for(int i =0;i<=V;i++)//We need a for loop for disconnected components. 
        {
            if(!vis[i])
            {
                if(dfs(i,-1, adj, vis)==true) return true;
            }
        }
        return false;
        
    }
}