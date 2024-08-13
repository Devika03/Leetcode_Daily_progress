// class Solution {
// public:
//     void BFS(vector<vector<int>>& graph , int source , vector<int>&color , vector<int>&visited , bool &is_Bip )
//     {
//         int col_1 = 0 ; 
//         int col_2 = 1 ; 
        
//         queue<int>q;
        
//         visited[source]= 1;
//         color[source]= col_1; int now_col =col_2;
//         q.push(source);
        
//         while(!q.empty())
//         {
//             int element = q.front();
//             q.pop();
//             for(auto it : graph[element])
//             {
//                 if(visited[it]==0)
//                 {
//                     visited[it]=1;
//                     color[it]=now_col;
//                     now_col= col_1;
//                 }
//                 if(visited[it]==1 && color[it]==now_col)
//                 {
//                     is_Bip = false;
//                     break;
//                 }
//             }
//         }
        
//     }
    
    
//     bool isBipartite(vector<vector<int>>& graph) 
//     {
//         int n = graph.size();
//         vector<int>color(n,-1);
//         vector<int>visited(n,0);
        
//         int source = 0 ;
//         bool is_Bip = true;
//         BFS(graph, source , color , visited , is_Bip);
//         return is_Bip;
        
        
        
//     }
// };



class Solution 
{
public:
    bool BFS(vector<vector<int>>& graph, int source, vector<int>& color) 
    {
        int col_1 = 0; 
        int col_2 = 1;
        bool is_Bip = true;
        
        queue<int> q;
        q.push(source);
        color[source] = col_1;
        
        while (!q.empty()) 
        {
            int element = q.front();
            q.pop();
            
            for (auto it : graph[element]) 
            {
                if (color[it] == -1)// if ( visited[it]== 0 ) 
                {
                    
                    color[it] = 1 - color[element];//Convert from 0 to 1  , 1 to 0 . 
                    q.push(it);
                } 
                else if (color[it] == color[element])
                {
                    is_Bip = false;
                    break;
                }
            }
        }
        
        return is_Bip;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // Initialize all nodes as uncolored
        
        // Perform BFS for every component of the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  // If the node is uncolored, start BFS from there
                if (!BFS(graph, i, color)) {
                    return false;
                }
            }
        }
        
        return true;  // If no conflicts found, graph is bipartite
    }
};
