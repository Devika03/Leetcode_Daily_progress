/*class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int index = -1;
        for( int i = n-2 ; i>=0 ; i--)
        {
           if(nums[i]<nums[i+1])
           {
               index = i ;
               break;
           }
        }
        if(index==-1)
        {
            reverse(nums.begin(), nums.end());
        }
        for(int j = n-1 ; j>=index ; j--)
        {
            if (nums[j] > nums[index])
            {
                swap(nums[j],nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index+1, nums.end() );
        
            }
}; */
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int index = -1;

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If no such element is found, reverse the entire array and return
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the element just larger than nums[index] to the right of index
        for (int j = n - 1; j > index; j--) {
            if (nums[j] > nums[index]) {
                swap(nums[j], nums[index]);
                break;
            }
        }

        // Step 3: Reverse the elements from index + 1 to the end of the array
        reverse(nums.begin() + index + 1, nums.end());
    }
};
