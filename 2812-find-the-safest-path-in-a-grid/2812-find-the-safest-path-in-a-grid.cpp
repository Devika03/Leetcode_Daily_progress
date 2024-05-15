class Solution {
public:
    bool check(vector<vector<int>> &vis,int i, int j,vector<vector<int>> &sf, int min)
    {
        int n = sf.size();
        if(i == n-1 && j == n-1)
        {
            return true;
        }
        if(sf[i][j] < min) return false;
        vis[i][j] = 1;
        bool f = 0;
        if(i+1 < n && sf[i+1][j] >= min && !vis[i+1][j])
        {
            f = f|check(vis,i+1,j,sf,min);
        }
        if(j+1 < n && sf[i][j+1] >= min && !vis[i][j+1])
        {
            f = f|check(vis,i,j+1,sf,min);
        }
        if(i-1 >= 0 && sf[i-1][j] >= min && !vis[i-1][j])
        {
            f = f|check(vis,i-1,j,sf,min);
        }
        if(j-1 >= 0 && sf[i][j-1] >= min && !vis[i][j-1])
        {
            f = f|check(vis,i,j-1,sf,min);
        }
        return f;
    }
     void bfs(int m, int n, vector<vector<int>> &d, const vector<pair<int, int>> &sources) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (const auto &source : sources) {
            q.push(source);
            d[source.first][source.second] = 0;
            vis[source.first][source.second] = 1;
        }

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();

            int r = tmp.first, c = tmp.second;

            for (int k = 0; k < 4; k++) {
                int nr = r + delr[k];
                int nc = c + delc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    d[nr][nc] = d[r][c] + 1;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> sf(n,vector<int>(n));
        vector<pair<int, int>> sources;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    sources.push_back({i,j});
                }
            }
        }
        bfs(n,n,sf,sources);
        // debug(sf)
        int ans = 0;
        int l = 0;
        int r = sf[0][0];
        while(l <= r)
        {
            vector<vector<int>> vis(n,vector<int>(n,0));
            int mid = (l+r)/2;
            int val = check(vis,0,0,sf,mid);
            // debug(mid)
            // debug(val)
            if(val == 1)
            {
                ans = max(ans,mid);
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
   }
};