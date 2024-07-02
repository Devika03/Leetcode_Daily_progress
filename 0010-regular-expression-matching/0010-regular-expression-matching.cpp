class Solution {
public:

    bool solve(long index1,long index2,string s,string p,vector<vector<int>>&dp)
    {
        if(index1<0 && index2<0)
        {
            return true;
        }

        if(index1<0)
        {
            while(index2>=0)
            {
                if(p[index2]!='*')
                {
                    return false;
                }
                index2-=2;
            }
            return true;
        }

        if(index1>=0 && index2<0)
        {
            return false;
        }

        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }

        if(s[index1]==p[index2] || p[index2]=='.')
        {
            dp[index1][index2]=solve(index1-1,index2-1,s,p,dp);
        }
        else if(p[index2]=='*')
        {
            bool zero=solve(index1,index2-2,s,p,dp);
            bool one=(index1>=0 && (s[index1]==p[index2-1] || p[index2-1]=='.')) &&
                        solve(index1-1,index2,s,p,dp);
            
            dp[index1][index2]=zero||one;
        }
        else
        {
            dp[index1][index2]=false;
        }
        return dp[index1][index2];
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(n-1,m-1,s,p,dp);
    }
};