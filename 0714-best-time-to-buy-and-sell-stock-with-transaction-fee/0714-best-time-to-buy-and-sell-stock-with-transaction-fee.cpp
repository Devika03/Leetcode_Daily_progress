class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0, check = INT_MIN;
        for(int i:prices){
            int temp = ans;
            ans = max(ans, check + i);
            check = max(check, temp - i - fee);
        }
        return ans;
    }
};