class Solution {
    int check(vector<vector<int>>& grid,int i,int j){
        int res=0;
        if(i+1>=grid.size()||grid[i+1][j]==0){
            res++;
        }
        if(i-1<0||grid[i-1][j]==0){
            res++;
        }
        if(j+1>=grid[0].size()||grid[i][j+1]==0){
            res++;
        }
        if(j-1<0||grid[i][j-1]==0){
            res++;
        }
        return res;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0,i=0;
        while(i<grid.size()){
            int j=0;
            while(j<grid[i].size()){
                if(grid[i][j]==1){
                    ans+=check(grid,i,j);
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};