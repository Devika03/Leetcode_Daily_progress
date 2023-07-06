class Solution {
public:
    
int minSubArrayLen(int target, vector<int>& nums) {
    int ans = INT_MAX,left=0,right=0;
    int sum=0,n=nums.size();
    while(right<n){
            // find sum of window starting from left
            sum=sum+nums[right];
        while(sum>=target){ 
            //if sum>=target store minimum ans and
            // current window length and move left pointer
            ans = min(ans,right-left+1);     
            sum-=nums[left];
            left++;
        }
            //increse the right pointer
            right++;
    }
    return ans==INT_MAX?0:ans;

    
}
};