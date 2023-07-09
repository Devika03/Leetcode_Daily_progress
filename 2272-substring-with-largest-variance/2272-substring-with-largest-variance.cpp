class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        set <char> chars(s.begin(),s.end());
        vector <char> dc(chars.begin(),chars.end());

        int m = dc.size();
        if(m==n) return 0;
        int ans = 0;
        for(auto c1:dc){
            for(auto c2:dc){
                if(c1==c2) continue;
                int cnt1 = 0,cnt2 = 0;
                bool starts_with_c1 = false;
                for(int i = 0;i < n;i++){
                    cnt1 += s[i]==c1;
                    cnt2 += s[i]==c2;
                    if(cnt1 > 0)
                        ans = max(ans,cnt2 - cnt1);
                    else if (cnt1 == 0 && starts_with_c1) {
                        ans = max(ans, cnt2 - 1);
                    }
                    if (cnt1> cnt2) {
                        cnt1 = cnt2 = 0;
                        starts_with_c1 = true;
                    }
                }
            }
        }
        return ans;
    }
};