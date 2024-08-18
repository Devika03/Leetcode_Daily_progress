class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int curr_diff = 0 ;
        int max_diff = -1;
        for(int i = 0 ; i < n-1 ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(nums[i]<nums[j])
                {
                    curr_diff=nums[j]-nums[i];
                    max_diff=max(curr_diff,max_diff);
                }
            }
        }
        return max_diff;
    }
};