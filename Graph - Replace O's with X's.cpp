class Solution{
    private:
    void dfs(int row , int col , vector<vector<int>> &vis , vector<vector<char>> &mat)
    {
        vis[row][col]=1;
        drow = {-1,0,1,0};
        dcol={0,1,0,-1};
        for(int i = 0 ; i<4 ;i++ )
        {
            int nrow= row+ drow[i];
            int ncol= col+dcol[i];
            if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && !vis[nrow][ncol]&& mat[nrow][ncol]=='O')
            {
                dfs(nrow,col,vis,mat);
            }
        }
    }
    public:
    vector<vector<char>>fill(int n , int m , vector<vector<char>>mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j = 0 ; j<m ;j++)//Trav. first row and last row. 
        {
            if(!vis[0][j]&&mat[0][j]=='O')//if first row is not vis. 
            {
                dfs(0,j,vis,mat);
            }
            if(!vis[n-1][j]&&mat[n-1][j]=='O')//if last row is not vis.
            {
                dfs(n-1,j,vis,mat);
            } 
        }
        for(int i = 0 ; i<n ; i++)
        {
            if(!vis[i][0] && mat[i][0]=='O')//First col. 
            {
                dfs(i,0,vis,mat);
            }
            if(!vis[i][m-1]&& mat[i][m-1]=='O')
            {
                dfs(i,m-1,vis,mat);
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(!vis[i][j]&& mat[i][j]=='O') mat[i][j]='X';
            }
        }
        return mat;
    }
}