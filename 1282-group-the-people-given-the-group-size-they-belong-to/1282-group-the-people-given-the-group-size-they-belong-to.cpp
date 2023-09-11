class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,int> mp;
        int n = groupSizes.size();

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int size = groupSizes[i];
            if(mp.count(size) && ans[mp[size]].size() < size){
                    ans[mp[size]].push_back(i);
            }
            else{
                ans.push_back({i});
                mp[size] = ans.size() - 1;
            }
        }

        return ans;
    }
};