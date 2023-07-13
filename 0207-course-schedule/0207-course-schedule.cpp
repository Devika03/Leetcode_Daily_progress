class Solution {
public:
    int vis[2005] = {0} ;
    int course[2005] = {0} ;
    bool dfs(int vertex , vector<vector<int>>&g )
    {
        if(vis[vertex]) return false ;  
        vis[vertex] = 1 ;
        course[vertex] = 1 ;
        for(auto child : g[vertex])
        {
            // cout<<vertex<<" "<<child<<" "<<endl;
            if(course[child]) return true ;  
            if(dfs(child,g)) return true ;
        }
        course[vertex] = 0 ;
        return false ;
    }
    // // // // //    Main Function of Question    ==========>
    // // // // //    Main Function of Question    ==========>
    //
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = numCourses ;
        int m = prerequisites.size() ;
        vector<vector<int>> g(n) ;
        for(int i=0; i<m; i++)
        {
            int a = prerequisites[i][0]  ;  
            int b = prerequisites[i][1]  ;  
            g[a].push_back(b) ;
        }
        for(int i=0; i<n; i++)
        {
            if(  g[i].size()>0 ) if(dfs(i,g)) return false ;
        }
        return true ;  
    }
};