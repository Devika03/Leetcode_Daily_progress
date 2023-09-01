class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> Ans(n+1, 0);
        for(int i = 0; i <= n; ++i){
            Ans[i]=Ans[i>>1]+(i&1);
        }
        return Ans;
    }
};