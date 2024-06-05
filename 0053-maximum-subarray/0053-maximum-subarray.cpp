class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int max =  INT_MIN;
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i]; //1. Handle Sum
            
            
            if (sum > max) max = sum; //2. Handle Max based on Sum
            if (sum < 0) sum = 0;
        }
        return max;
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