class Solution {
public:
    int passThePillow(int n, int time) {
        int ans;
        int noc = ceil((double)(time)/(double)(n-1));
        int help = time - (noc - 1)*(n - 1); 
        if(noc%2 == 0)
            ans = (n-1) - (help - 1);
        else
            ans = help + 1;
        return ans;
    }
};