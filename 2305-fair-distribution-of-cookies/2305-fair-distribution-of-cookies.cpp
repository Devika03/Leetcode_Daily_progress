class Solution {
public:
    int ans = INT_MAX;
    void solve(int idx,int k,vector<int> &v,vector<int>& cookies){
        if(idx == cookies.size()){
            int m = 0;
            for(auto c:v)
                m = max(m,c);
            ans = min(ans,m);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += cookies[idx];
            solve(idx+1,k,v,cookies);
            v[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        solve(0,k,v,cookies);
        return ans;
    }
};