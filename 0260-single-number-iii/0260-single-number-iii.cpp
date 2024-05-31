class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<int, bool> mp;
        for(auto &it : nums) {
            if(mp.count(it)) {
                mp.erase(it);
            }else {
                mp[it] = true;
            }
        }
        auto it  = mp.begin();
        return {it->first, (++it)->first};
    }
};