class Solution {
    // MLE if string not passed with reference
    int dfs(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1e9;
        if(s1[i]==s2[j])
        {
            ans = min(ans,-2*s1[i]+dfs(i-1,j-1,s1,s2,dp));
        }
        ans = min(ans,min(dfs(i-1,j,s1,s2,dp),dfs(i,j-1,s1,s2,dp)));
        return dp[i][j] = ans;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        int n = s1.length();
        int m = s2.length();
        for(auto &i:s2)sum+=i;
        for(auto &i:s1)sum+=i;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return sum+dfs(n-1,m-1,s1,s2,dp);
    }
};