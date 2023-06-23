class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
    
        int n = nums.size();
        int maxCount = 0;
        unordered_map<int,vector<int>>mp;
        for (int i = 0; i < n; i++) {
           for(int j=0;j<i;j++)
           {
              int diff=nums[j]-nums[i];
              if(mp.find(diff)==mp.end())
              {
                  mp[diff]=vector<int>(1000,1);
              }
              mp[diff][i]=max(mp[diff][i],mp[diff][j]+1);
              maxCount=max(maxCount,mp[diff][i]);
           }
        }
        
        return maxCount;
    }
};
