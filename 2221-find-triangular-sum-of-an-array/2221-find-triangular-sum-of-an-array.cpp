/*class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        vector<vector<int>>res;
        int sizeofnums = nums.size();
        for(int j=1 ; j<sizeofnums ; j++)
        {    
        vector<int>temp(sizeofnums-j,0);//As from 2 ends , Elements are chopped off .
        
        for(int i = 0 ; i<temp.size() ; i++)
        {
            temp[i] = (nums[i] + nums[i + 1]) % 10;
        }
        nums=temp;
        res.push_back(temp);
        }
        vector<int> lastVector = res.back();
        return lastVector[0];
        */
        
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        while(n!=1){
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
};
    
    