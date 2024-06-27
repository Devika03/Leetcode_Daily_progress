class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(n == 0) return -1;
        else if (n == 1) return nums[0];
        else if(nums[start] != nums[start+1]) return nums[start];
        else if(nums[end] != nums[end-1]) return nums[end];

        while(start<=end){
        
        int mid=start+(end-start)/2;

            //check whether mid is not the single one
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            return nums[mid];
        
        //check which half contain single element
        if((mid%2==0 && nums[mid] == nums[mid+1]) || (mid%2==1 && nums[mid] == nums[mid-1])){
            //first half do not contain single element
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        }
        return -1;

    }
};