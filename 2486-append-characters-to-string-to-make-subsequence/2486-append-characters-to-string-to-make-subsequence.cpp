class Solution {
public:
    int appendCharacters(string s, string t) {
        int l1=0,l2=0;
        int n=s.size(),m=t.size();
        int h1=n-1,h2=m-1;
        while(l1<=h1 && l2<=h2){
            if(s[l1]==t[l2]){
                l1++;
                l2++;
            }
            else{
            l1++;
            }
        }
        cout<<l2;
        return h2-l2+1;
    }
};