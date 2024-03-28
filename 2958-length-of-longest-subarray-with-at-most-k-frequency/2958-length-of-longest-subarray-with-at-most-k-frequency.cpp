class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int start=0,end=0,n=nums.size(),len=0;
        while(end<n){
         mp[nums[end]]++;
         while(start<=end && mp[nums[end]]>k){
            mp[nums[start]]--;
            start++;
         }
         len=max(len,end-start+1);
         end++;
        }
        return len;
    }
};