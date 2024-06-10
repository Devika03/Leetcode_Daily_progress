class Solution {
public:
    int mod(int m , int M)
    {
        return(m%M+M)%M;
    }
    int add(int a , int b , int M)
    {
        return mod(mod(a,M)+mod(b,M),M);
    }
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        map<int,int>a;
        int total_sum = 0;
        a[0]=1;
        int total_subarray=0;
        for(int i =0 ; i<nums.size() ;i++)
        {
            total_sum = add(nums[i], total_sum , k);
            total_subarray+= a[total_sum];
            a[total_sum]++;
        }
        return total_subarray;
    }
};