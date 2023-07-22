class Solution {
private:
    bool isValid(int r, int c, int n){
        if(r>=0 && r<n && c>=0 && c<n)return true;
        return false;
    }
private:
    double f(int r, int c, int n, int k, int dx[], int dy[], vector<vector<vector<double>>> &dp){
        if(!isValid(r,c,n))return 0;
        if(k==0)return 1;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        double ans = 0;
        for(int i =0;i<8;i++){
            int nextR = r+dx[i];
            int nextC = c + dy[i];
            ans = ans+f(nextR, nextC, n, k-1, dx, dy,dp);
        }
        return dp[r][c][k] = ans;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        int dx[8] = {-2,-2,-1,-1,1,1,2,2};
        int dy[8] = {-1,1,-2,2,-2,2,-1,1};
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1,-1)));
        double validDest = f(row, column, n,k,dx, dy,dp);
        return (double) validDest/pow(8,k);
    }
};