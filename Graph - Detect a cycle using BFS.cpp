class Solution 
{
    private:
    bool detect(int source,vector<int>adj[],int vis[])
    {
        vis[source]=1;
        queue<pair<int,int>>q; //Neighbour node ,Source node
        q.push({source,-1});//Initially.
        while(!q.empty())
        {
            int node = q.front().first;
            int parent =q.front().second;
            q.pop();

            for (auto adjacentnode:adj[node])
            {
                if(!vis[adjacentnode])
                {
                    vid[adjacentnode]=1;
                    q.push({adjacentnode  , node});
                }
                else if(parent !=adjacentnode)//If someone is vis . and it did not come from it . 
                {
                    return True;
                }
            }
        }
        return False;
    }
    public:
    bool isCycle(int V , vector<int> adj[])
    {
        int vis[V]={0};
        for(int i = 0 ; i<=V ; i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis))return True;
            }
            
        }
        return False;
    }
}