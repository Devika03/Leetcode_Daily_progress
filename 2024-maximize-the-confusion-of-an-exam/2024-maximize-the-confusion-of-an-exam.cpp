class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int cntT=0, cntF=0;
        int i=0,j=0;
        int ans=0;
        while(j<a.size()){
            if(a[j]=='F')cntF++;
            else cntT++;
            
            while(min(cntT,cntF)>k){
                if(a[i]=='F')cntF--;
                else cntT--;
                i++;
            }
            ans=max(ans,cntT+cntF);
            j++;
        }
        return ans;
    }
};