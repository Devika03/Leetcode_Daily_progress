class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>uttar;
        vector<int>v;
        while (!mp.empty()) {
            for(auto it = mp.begin(); it != mp.end();) {
                v.push_back(it->first);
                it->second--;
                if (it->second == 0) it = mp.erase(it);
                else ++it;
            }
            uttar.push_back(v);
            v.clear();
        }
        return uttar;
    }
};
