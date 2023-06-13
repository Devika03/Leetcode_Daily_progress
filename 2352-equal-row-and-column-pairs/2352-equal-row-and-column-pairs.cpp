class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        int n = grid.size();

        for(int i = 0 ; i < n ; i++){
            m[grid[i]]++;
        }

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            vector<int> val;
            for(int j = 0 ; j < n ; j++){
                val.push_back(grid[j][i]);
            }

            if(m.find(val)!=m.end()){
                cnt+=m[val];
            }
        }

        return cnt;
    }
};