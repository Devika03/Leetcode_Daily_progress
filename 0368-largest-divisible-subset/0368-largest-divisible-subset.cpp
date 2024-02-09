class Solution {
public:
    vector<int> solve(vector<int>& nums) {
        int n = size(nums);
        sort(nums.begin(),nums.end());
        int dp[10003];
        for(int i=0;i<=10000;++i){
            dp[i] = 1;
        }
        unordered_map<int,int>mp;
        mp[nums[0]] = -1;
        for(int i=1;i<n;++i){
            mp[nums[i]] = -1;
            for(int j=i-1;j>=0;--j){
                if(nums[i]%nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = 1 + dp[j];
                        mp[nums[i]] = nums[j];
                    }
                }
            }
        }
        int ans = 0 , value = 0;
        for(int i=0;i<n;++i){
            if(dp[i] > ans){
                value = nums[i];
                ans = dp[i];
            }   
        }
        vector<int>res;
        res.push_back(value);

        int ind = mp[value];
        while(ind!=-1){
            res.push_back(ind);
            ind = mp[ind];
        }
        return res;
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return solve(nums);
    }
};

