class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        int mx = 0;
        unordered_map<int, int> mp;
        for(auto i:e)
        {
            mx = max({i[0],i[1],mx});
            mp[i[0]]++;
            mp[i[1]]++;
            
        }

        for(auto i: mp)
        {
            if(i.second == (mx-1))
                return i.first;
        }
        
        return -1;
        
        
        
        
    }
};