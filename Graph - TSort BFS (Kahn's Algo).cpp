class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
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
	    vector<int>topo;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        // node is in your topo sort vector so we deduct 1 from the indegree
	        for(auto it : adj[node] )
	        {
	            in[it]--;
	            if(in[it]==0) q.push(it);
	        }
	    }
	    return topo;
	    
	}	
};