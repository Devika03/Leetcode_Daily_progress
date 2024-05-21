class Solution {
public:
    void recursion(int idx, vector<int> &nums, vector<int> &subset,int &sum){
        if(idx == nums.size()){
            int temp = 0;
            for(auto it: subset){
                temp = it^temp;
            }
            sum += temp;
            return;
        }
        recursion(idx+1,nums,subset, sum);
        subset.push_back(nums[idx]);
        recursion(idx+1,nums,subset, sum);
        subset.pop_back();
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;
        int sum = 0;
        recursion(0,nums,subset,sum);
        return sum;
    }
};