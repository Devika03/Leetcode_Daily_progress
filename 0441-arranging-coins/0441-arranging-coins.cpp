class Solution 
{
public:
    vector<long long> cost(int x)
    {
        long long tmp = (long long) x;
        long long steps = tmp * (tmp + 1) / 2; 
        vector<long long > res = {steps, x}; 
        return res; 
    }
    int arrangeCoins(int n) 
    {
        int left = 1,  right = n; 
        int ans = 0; 

        while( left <= right)
        {
            long long pivot = left + (right - left) / 2; 
            vector<long long> ans = cost(pivot); 
            if(ans[0] == n)
                return ans[1]; 
            else if(ans[0] < n)
                left = pivot + 1; 
            else 
                right = pivot - 1; 
        }

        // Checking if it's complete or not.
        vector<long long> res = cost(left); 
        if(res[0] == n)
            return left;
        else
            return left - 1;  
        return left; 
    }
};