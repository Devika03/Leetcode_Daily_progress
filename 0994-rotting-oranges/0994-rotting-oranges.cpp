class Solution {

private:
    int bfs(queue<pair<int, int>> que, vector<vector<int>> &grid, int r[], int c[]){
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        while(!que.empty()){
            int size = que.size();
            bool isRotten = false;  // if rotten oranges can't rotten any oranges

            for(int i=0; i<size; i++){
                int row = que.front().first;
                int col = que.front().second;

                que.pop();

                for(int i=0; i<4; i++){
                    int nr = row + r[i];
                    int nc = col + c[i];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                        isRotten = true;
                        grid[nr][nc] = 2;
                        que.push({nr,nc});
                    } 
                }
            }

            if(isRotten) time++;
        }

        return time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int n = grid.size();
        int m = grid[0].size();

        // checking the rotten oranges in the grid the pushing it to que
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }
            }
        }

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, -1, 1}; 

        int rottenTime = bfs(que, grid, r, c);

        // checking if any not rotten oranges left, if yes then returning -1
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return rottenTime;
    }
};