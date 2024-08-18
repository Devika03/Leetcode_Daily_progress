class Solution 
{
public:
int sumOfBeauties(vector<int>& nums) 
{
    int n=nums.size();
    int sum_of_b = 0 ; 
    vector<int>P_Max_Sum(n);
    vector<int>S_Min_Sum(n);
    
    int ele = nums[0];
    for(int i=0;i<n;i++) 
    {
        ele=max(ele,nums[i]); 
        P_Max_Sum[i]= ele;
    }
    ele=nums[n-1];
    
    for(int i=n-1;i>=0;i -- ) 
    {
        ele=min(ele,nums[i]);
        S_Min_Sum[i]= ele;
    }
    for(int i=1;i<n-1;i++)
    {
    if(nums[i]>P_Max_Sum[i-1] && nums[i]<S_Min_Sum[i+1]) sum_of_b+=2;
    else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]) sum_of_b++;
}
return sum_of_b;
}};