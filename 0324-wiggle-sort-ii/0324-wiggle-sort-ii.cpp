/*class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>new_nums;
        sort(nums.begin(),nums.end());
        int j =n-1;
        for(int i =0 ; i<j ; i++,j--)
        {
            new_nums.push_back(nums[i]);
            new_nums.push_back(nums[j]);
        }
        nums=new_nums;
        }
};*/
class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {


        // sorting the nums
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>temp(n);
        int i=1;
        int j=n-1;
        while(i<n)
        {
            temp[i]=nums[j];
            j--;
            i+=2;
        }
        i=0;
        while(i<n)
        {
            temp[i]=nums[j];
            j--;
            i+=2;
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=temp[i];
        }
        
       
    }
};