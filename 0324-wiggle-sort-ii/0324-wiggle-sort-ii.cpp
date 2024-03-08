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
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Find the mid point of the array
        int mid = (n + 1) / 2;
        
        // Create a temporary array to store the rearranged elements
        vector<int> result(n);
        
        // Place the larger elements in even indices
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                result[i * 2] = nums[mid - 1 - i];
            }
            // Place the smaller elements in odd indices
            else {
                result[(i - mid) * 2 + 1] = nums[n - 1 - (i - mid)];
            }
        }
        
        // Copy the rearranged elements back to the original array
        nums = result;
    }
};
