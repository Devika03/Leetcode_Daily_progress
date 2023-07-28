class Solution {
public:

    int dp[21][21];

    int f(int i, int j, vector<int>& nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = nums[i] - f(i + 1, j, nums);
        ans = max(ans, nums[j] - f(i, j - 1, nums));
        return dp[i][j] = ans;
    }

    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return f(0, nums.size() - 1, nums) >= 0;
    }
};