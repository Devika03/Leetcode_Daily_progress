class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>avgs(nums.size(),-1);
        long sum=0;
        int i=0,j=0;
        int window=2*k+1;
        while(j<nums.size())
        {
            sum+=nums[j];
            if((j-i+1)==window)
            {
                avgs[j-k]=sum/window;
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return avgs;
    }
};