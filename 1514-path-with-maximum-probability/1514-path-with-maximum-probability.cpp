class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double>dist(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            double p=it.first;
            for(auto it:adj[node]){
                if(dist[it.first] < p*it.second){
                    dist[it.first]=p*it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist[end];
    }
};