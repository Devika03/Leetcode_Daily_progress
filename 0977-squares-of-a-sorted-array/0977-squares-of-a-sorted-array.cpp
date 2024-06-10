class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            nums[i] = nums[i]*nums[i];
        }
        
        for(int i = 0 ; i<n-1 ; i++)
        {
            int swapped = 0 ; 
            for(int j = 0 ; j<n-i-1 ; j++)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    swapped = 1; 
                }
            }
            if(swapped==0) break;
        }
        return nums;
    }
        
};