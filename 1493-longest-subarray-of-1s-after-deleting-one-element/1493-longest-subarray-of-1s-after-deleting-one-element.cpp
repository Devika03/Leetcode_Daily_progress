class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0, before=0, after=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans=max(ans,(before+after));
                before=after;
                after=0;
            }
            else
            {
                after++;
            }
        }
        ans=max(ans,(before+after));

        if(ans==nums.size()) return ans-1;
        return ans;

        
    }
};