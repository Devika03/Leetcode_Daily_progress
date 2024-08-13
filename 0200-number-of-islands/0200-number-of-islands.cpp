class Solution {
public:
    void BFS(vector<vector<char>>& grid , int i , int j , vector<vector<int>>&visited , int m , int n )
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        
        int drow[] = {-1 , 0 , 0 , 1 };
        int dcol[] = {0 , 1 , -1 , 0 };
        
        while(!q.empty())
        {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int loop = 0 ; loop < 4 ; loop++)
        {
                int nrow = r+drow[loop];
                int ncol = c+dcol[loop];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol < n && grid[nrow][ncol]=='1' && visited[nrow][ncol]== 0 )
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
        
    
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0 ; 
        int m = grid.size();//4 Rows .
        int n = grid[0].size();//Columns : 5 Elements in each Row .
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '1')
                {
                    if(visited[i][j]==0)
                    {
                        BFS(grid, i , j , visited , m , n );
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
};

















//         if(grid.empty() || grid[0].empty())
//             return 0;
        
//         int rows = grid.size();
//         int cols = grid[0].size();
//         int islands = 0;
        
//         function<void(int, int)> dfs = [&](int row, int col) {
//             if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != '1')
//                 return;
//             grid[row][col] = '0';
//             dfs(row - 1, col);
//             dfs(row + 1, col);
//             dfs(row, col - 1);
//             dfs(row, col + 1);
//         };
        
//         for(int row = 0; row < rows; row++) {
//             for(int col = 0; col < cols; col++) {
//                 if(grid[row][col] == '1') {
//                     dfs(row, col);
//                     islands++;
//                 }
//             }
//         }
        
//         return islands;