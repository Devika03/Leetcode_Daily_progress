class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int dp[n][5001];
        int ans=0, mod=1e9+7;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5001;j++)
                dp[i][j]=-mod;
        }
        
        dp[0][rods[0]]=rods[0];
        dp[0][0]=0;
        
        for(int i=1;i<n;i++)
        {
            for(int diff=0;diff<3000;diff++)
            {
                dp[i][diff]=max(dp[i-1][diff],rods[i]+max(dp[i-1][diff+rods[i]],dp[i-1][abs(diff-rods[i])]));
            }
        }
        ans = dp[n-1][0]/2;
        return ans;
    }
};