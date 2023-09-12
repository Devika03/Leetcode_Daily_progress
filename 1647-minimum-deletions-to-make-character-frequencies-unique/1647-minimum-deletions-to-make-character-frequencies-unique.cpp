class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;

        for(auto c : s){
            mp[c-'a']++;
        }

        vector<int> ans;
        unordered_map<char,int>::iterator it;
        for(it = mp.begin(); it!=mp.end(); it++){
            ans.push_back(it->second);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        int count = 0;

        for(int i = 1; i<ans.size(); i++){
            while((ans[i] == ans[i-1] || ans[i] > ans[i-1]) && ans[i] > 0){
                count++;
                ans[i]--;
            }
        }
        return count;
    }
};