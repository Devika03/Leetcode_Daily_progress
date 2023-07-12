class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<int>> vis(n,vector<int>(m, 0));//Vis
        vector<vector<int>> dis(n,vector<int>(m, 0));//Dist.
        queue<pair<pair<int, int>, int>> q;//(i,j),dist.

   for(int i=0; i<n; i++)
   {
       for(int j=0; j<m; j++)
       {
           if(grid[i][j]==0)//They will be our source and will be pushed into our q first. 
           {
              q.push({{i,j},0});
              vis[i][j]=1;
           }
       }
   }

int dr[]= {-1, 1, 0,0};
int dc[]= {0,0,1,-1};

while(!q.empty())
{

int x= q.front().first.first;//Storing the front ele.s dets. 
int y= q.front().first.second;
int steps= q.front().second;
q.pop();

dis[x][y]= steps;

for(int i=0; i<4; i++)
{
   int nx= x+ dr[i];
   int ny= y+ dc[i];

  if(nx>=0 && nx<n/* Checking if it is within the matrix */&& ny>=0 && ny<m && grid[nx][ny]==1 && !vis[nx][ny])
  {    vis[nx][ny]=1;
       q.push({{nx,ny},steps+1});
          } 
     }
  }
return dis;
}

};
