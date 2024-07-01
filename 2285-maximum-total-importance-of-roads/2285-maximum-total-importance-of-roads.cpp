class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> adj[n];
        for(auto it: roads){
            long long u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long> v(n);//adj[node].size() and val
        for(int i=0; i<n; i++){
            v[i] = adj[i].size();
        }
        sort(v.begin(), v.end());
        long long sum = 0;
        long long k = n;
        for(int i=n-1; i>=0; i--){
            sum += (k*v[i]);
            k--;
        }
        return sum;
    }
};