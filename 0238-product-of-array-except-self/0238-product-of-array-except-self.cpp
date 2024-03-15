class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int l = 1;
        int r = 1;
        for (int i=0; i<n; i++){
            left[i] = l;
            l *= nums[i];
        }
        for (int i=n-1; i>=0; i--){
            right[i] = r;
            r *= nums[i];
        }
        for (int i=0; i<n; i++){
            result[i] = left[i] * right[i];
        }
        return result;
    }
};