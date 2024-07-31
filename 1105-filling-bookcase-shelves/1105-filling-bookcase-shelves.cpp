class Solution {
public:
    vector<int> dp;
    int helper(int i,vector<vector<int>>& books,int sw){
        if(i>=books.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int currSW=0,currMaxSH=0,ans=INT_MAX;
        for(int j=i;j<books.size() && currSW<=sw;j++){
            int tbw=books[j][0],tbh=books[j][1];
            currSW+=tbw;
            if(currSW>sw){break;}
            currMaxSH=max(currMaxSH,books[j][1]);
            ans=min(ans,currMaxSH+helper(j+1,books,sw));
        }
        return dp[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp=vector<int> (books.size()+1,-1);
        return helper(0,books,shelfWidth);
    }
};