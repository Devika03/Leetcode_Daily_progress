class Solution
{
    public:
    int numberOfEnclaves(vector<vector<int>>&grid)
    {
        queue<pair<int,int>> q;
        int n= grid.size();
        int m = grid[0].size();
        int vis[n][m]={0};
        for(int i =0 ; i <n;i++)
        {
            for(int j = 0 ; j<m ; j++)
            {   //first row , first col , last row , last col 
                if(i==0 || j==0 || i ==n-1 ||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int drow[]= {-1,0,1,0};
        int dcol[]= {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //Traverse all 4 direc. 
            for(int i = 0 ; i<4 ; i++)
            {
                int nrow= row + drow[i];
                int ncol= col + dcol[i] ;
                if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
            int cnt = 0 ;
            for (int i = 0 ; i<n ; i++)
            {
                for(int j = 0 ; j < m ; j++)
                {
                    if(grid[i][j]==1 && vis[i][j]==0)
                    cnt++;
                }
            }
            return cnt;
        }
    }
