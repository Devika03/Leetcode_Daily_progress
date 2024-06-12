/*class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int element=-1;
        
        unordered_map<int,int>map;
        for(int i = 0 ; i<nums.size() ; i++)//0 1 2 3 
        {
            map[nums[i]]=0;
        }
        for(int i = 0 ; i<nums.size() ; i++)
        {
            map[nums[i]]++;
        }
        
        for(int i = 0 ; i<map.size() ; i++)
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
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int element = 0;

        // Initialize the map to count occurrences
        unordered_map<int, int> map;
        
        // Initialize map with all possible numbers from 0 to n with count 0
        for(int i = 0; i <= n; i++) // Loop goes up to n inclusive
        {
            map[i] = 0;
        }

        // Count the occurrences of each number in nums
        for(int i = 0; i < n; i++) // Loop through nums, valid index from 0 to n-1
        {
            map[nums[i]]++;
        }
        
        // Find the missing number
        for(int i = 0; i <= n; i++)
        {
            if(map[i] == 0) 
            {
                element = i;
                break;
            }
        }
        
        return element;
    }
};
