/*class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int max = nums[0];//or INT_MIN
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i]; //1. Handle Sum
            
            if (sum < 0) sum = 0;
            if (sum > max) max = sum; //2. Handle Max based on Sum
            
        }
        return max;
    }
};*/
    
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int max_sum = nums[0]; // Initialize max_sum to the first element
        
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i]; // Handle Sum
            
            if (sum > max_sum) 
                max_sum = sum; // Update max_sum if the current sum is greater
            
            if (sum < 0) 
                sum = 0; // Reset sum if it is negative
        }
        return max_sum;
    }
};
















/*
int sum = 0;
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum < 0) sum = 0;
        }
        return max; */


/* O( N^3 ) : 

int maxSubArray(vector<int>& nums) 
    {
      int sum = INT_MIN;
      int n = nums.size();
      for(int i = 0 ; i<n ; i++)
      {
          for(int j = i ; j<n ; j++)
          {
              int curr_sum=0;
              for(int k = i ; k <= j ; k++)
              {
                  curr_sum+= nums[k];
              }
              sum = max(sum,curr_sum);
          }
          
      }
        return sum;
    }

*/