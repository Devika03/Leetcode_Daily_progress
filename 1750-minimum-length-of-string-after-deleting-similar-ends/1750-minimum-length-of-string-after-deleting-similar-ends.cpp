class Solution {
public:
    int minimumLength(string s) {
        int i=0, j=s.size()-1;
        if(s.size()==1) return 1;
        while (i<j) {
            while(i<s.size()-1 && s[i] == s[i+1] && s[i]==s[j]) i++;
            while(j>0 && s[j] == s[j-1] && s[i]==s[j]) j--;
            if(s[i]==s[j] && i<s.size()-1 && j>0) {
                i++;
                j--;
            } else {
                break;
            }
        }
        if(s[i] == s[j] && j<i) {
            return 0;
        } else if(s[i] == s[j] && i==j) {
            return 1;
        } else {
            return j-i+1;
        }
    }
};