class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,int>first_Occ;
        map<int,int>second_Occ;
        map<int,int>count;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(first_Occ.find(nums[i])==first_Occ.end())
            {
                first_Occ[nums[i]]=i;
            }
            second_Occ[nums[i]]=i;
            count[nums[i]]++;
        }
        int degree = INT_MIN;
        for(auto x : count)
        {
            degree = max(degree,x.second);
        }
        
        int ans = nums.size(); //At max. , The entire array is the answer itself. 
        for(auto x: count)
        {
            if(x.second == degree)
            {
                int ele = x.first;
                ans = min (ans , second_Occ[ele] - first_Occ[ele]+1);
            }
        }
        return ans;
        
    }
};