class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) 
        {
            // int mid = (low + high) / 2; Not Working 
            int mid = low + (high - low) / 2; // Use this alternative to avoid OF.

            if (nums[mid] < nums[high]) 
            {
                high = mid;
            } else 
            {
                low = mid + 1;
            }
        }

        return nums[low];
    }
};