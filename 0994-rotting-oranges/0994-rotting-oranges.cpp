class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;//Co.od , time .
        int fresh = 0 , afterfresh = 0; 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n,vector<int>(m,0));

        for(int i =0;i<n;i++)
        {
            for(int j = 0; j<m;j++)
            {
                if(grid[i][j]==2)//All rotten oranges are pushed to q. 
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                 if(grid[i][j]==1)//If not 2 then it is fresh. 
                 fresh++;
            }
        }

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int time = 0; 
        int res = 0; 

        while(!q.empty() ){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            res = max(res,t);
            q.pop();
            for(int i = 0; i<4;i++){
                int r = row + drow[i];//We are  appending and reaching the neighbors. 
                int c = col + dcol[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && vis[r][c]==0) //We are checking the neighbors if they are eligible to be pushed into the queue. 
                {
                    q.push({{r,c},t+1});
                    vis[r][c]=2;
                    afterfresh++;
                }

            }



        }
            if(fresh!=afterfresh)
            return -1;
            return res;

        return res;}};