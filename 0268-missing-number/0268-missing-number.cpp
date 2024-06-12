class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int element=-1;
        
        unordered_map<int,int>map;
        for(int i = 0 ; i<=nums.size() ; i++) //0 1 2 3 
        {
            map[i]=0;
        }
        for(int i = 0 ; i<nums.size() ; i++)
        {
            map[nums[i]]++;
        }
        
        for(int i = 0 ; i<= nums.size() ; i++)
        {
            if(map[i]==0) 
            {
                element = i;
                break;
            }
        }
        return element;
        
    }
};
