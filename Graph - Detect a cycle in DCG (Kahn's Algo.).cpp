class Solution
{
	public:
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    int in[V]={0};
	    for(int i =0 ; i<V;i++)
	    {
	        for(auto it : adj[i] )
	        {
	            in[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i =0 ; i<V;i++)
	    {
	        if(in[i]==0) q.push(i);
	    }
        int cnt = 0;

	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        cnt++;
	        // node is in your topo sort vector so we deduct 1 from the indegree
	        for(auto it : adj[node] )
	        {
	            in[it]--;
	            if(in[it]==0) q.push(it);
	        }
	    }
        if(cnt== V) return false;
        return true;
	    
	}	
};