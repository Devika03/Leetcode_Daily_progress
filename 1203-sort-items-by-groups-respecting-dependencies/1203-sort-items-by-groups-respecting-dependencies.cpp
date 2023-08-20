class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Step 1: Handle isolated items by assigning them to unique groups.
        for(int i = 0; i < n; i++){
            if (group[i] == -1) group[i] = m++;
        }
        
        // Step 2: Create adjacency lists for groups and items, and calculate their in-degrees.
        vector<vector<int>> adjGroup(m), adjItem(n);
        vector<int> degGroup(m, 0), degItem(n, 0);
        
        for(int i = 0; i < n; i++){
            int toItem = group[i];
            for(int fromItem : beforeItems[i]){
                int fromGroup = group[fromItem];
                if(toItem != fromGroup){
                    adjGroup[fromGroup].push_back(toItem);
                    degGroup[toItem]++;
                }
                adjItem[fromItem].push_back(i);
                degItem[i]++;
            }
        }
        
        // Step 3: Topologically sort groups and items.
        vector<int> sortedGroups = topoSort(adjGroup, degGroup, m);
        vector<int> sortedItems = topoSort(adjItem, degItem, n); 
        
        // Step 4: Check if topological sort is possible.
        if (sortedGroups.empty() || sortedItems.empty()) return {};

        // Step 5: Organize items within their respective groups.
        vector<vector<int>> itemGroups(m);
        for(int i : sortedItems)
            itemGroups[group[i]].push_back(i);
        
        // Step 6: Combine sorted groups and their items into the final result.
        vector<int> result;
        for(int i : sortedGroups) {
            for(int item : itemGroups[i]) {
                result.push_back(item);
            }
        }
        
        return result;
    }

private:
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& deg, int sz){
        // Kahn's algorithm for topological sorting.
        queue<int> q;
        for (int i = 0; i < sz; i++)
            if (deg[i] == 0) q.push(i);
        vector<int> res;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            res.push_back(x);
            for(int y : adj[x]){
                deg[y]--;
                if(deg[y] == 0) q.push(y);
            }
        }
        // Check if topological sort is possible (no cycles).
        for(int i = 0; i < sz; i++)
            if(deg[i] > 0) return {};
        return res;
    }
};