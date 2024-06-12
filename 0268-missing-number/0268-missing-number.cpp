class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int element = -1;
        
        // Create a boolean array to mark the presence of each number
        vector<bool> present(n + 1, false);
        
        // Mark the presence of each number in the array
        for(int i = 0; i < n; i++)
        {
            present[nums[i]] = true;
        }
        
        // Find the first number that is not present
        for(int i = 0; i <= n; i++)
        {
            if(!present[i])
            {
                element = i;
                break;
            }
        }
        
        return element;
    }
};
