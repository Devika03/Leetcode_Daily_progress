class Solution {
public:
    bool check(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int minimumEffortPath(vector<vector<int>>& h) 
    {
        
        
        int n=h.size(),m=h[0].size();
        
        vector<pair<int,int>> v={{1,0},{-1,0},{0,1},{0,-1}};
        //vector<vector<int>> dp(n,vector<int>(n,0));
    
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int val,nx,ny,x,y,diff,maxi;
        
        pq.push({dist[0][0],{0,0}});
        
        while(!pq.empty())
        {
            val=pq.top().first;
            x=pq.top().second.first;
            y=pq.top().second.second;
            pq.pop();
            
            if(x==n-1 && y==m-1)
            {
                return val;   
            }
            
            for(int i=0;i<4;i++)
            {
                nx=x+v[i].first;
                ny=y+v[i].second;
                
                if(check(nx,ny,n,m))
                {
                    maxi=max(abs(h[nx][ny]-h[x][y]),val);//decide who wants to be the updated cost for nx,ny the historical minimum cost or the new one , of these two the maximum one will be updated
                    if(dist[nx][ny]>maxi)
                    {
                        dist[nx][ny]=maxi;
                        pq.push({maxi,{nx,ny}});
                    }
                }
            }
        }
        
        return 0;
    }
};