class Solution {
public:
    vector<int>nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int index = -1;
        for( int i = n-2 ; i>=0 ; i--)
        {
           if(nums[i]<nums[i+1])
           {
               index = i ;
               break;
           }
        }
        if(index==-1)
        {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        for(int j = n-1 ; j>=index ; j--)
        {
            if (nums[j] > nums[index])
            {
                swap(nums[j],nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index+1, nums.end() );
        return nums;
        }
    
    vector<vector<int>> permuteUnique(vector<int>&nums) 
    {
        queue<vector<int>>q;
        vector<vector<int>>result;
        
        result.push_back(nums);
        q.push(nums);
        
        while(!q.empty())
        {
            vector<int>curr_element = q.front();
            q.pop();
            
            vector<int>next_perm = nextPermutation(curr_element);
            if(next_perm != result[0])
            {
                q.push(next_perm);
                result.push_back(next_perm);
            }
        }
        return result;        
    }
};