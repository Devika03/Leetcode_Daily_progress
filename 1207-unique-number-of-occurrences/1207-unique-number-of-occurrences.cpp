class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            for(auto i:mp){
                if(i.first!=it.first){
                    if(it.second == i.second)return false;
                }
            }
        }
        return true;
    }
};