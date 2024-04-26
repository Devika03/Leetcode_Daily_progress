class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini = INT_MAX, secMin = INT_MAX;
        for(int i = 0; i < grid.size(); i++) {
            int nextMini = INT_MAX, nextSecMin = INT_MAX;
            for(int j = 0; j < grid[0].size(); j++) {
                if(i) 
                    grid[i][j] += grid[i - 1][j] == mini? secMin: mini;
                if(grid[i][j] < nextMini) {
                    nextSecMin = nextMini;
                    nextMini = grid[i][j];
                } else {
                    nextSecMin = min(grid[i][j], nextSecMin);
                }
            }
            mini = nextMini;
            secMin = nextSecMin;
        }
        return mini;
    }
};