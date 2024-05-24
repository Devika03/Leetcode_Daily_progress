class Solution {
public:
    unordered_map<int,int>m;
    int rec(vector<int>& nums, int k ,int idx , int prev)
    {
        if(idx>=nums.size())
        return 1;

        int total = 0;

        total+= rec(nums,k,idx+1,prev);

        if(prev==-1 || m[nums[idx]-k]==0 )
        { m[nums[idx]]=1;
            total+= rec(nums,k,idx+1,idx);
         m[nums[idx]]=0;
        }

        return total;




    }
    int beautifulSubsets(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        return rec(nums,k,0,-1)-1;
        
    }
};