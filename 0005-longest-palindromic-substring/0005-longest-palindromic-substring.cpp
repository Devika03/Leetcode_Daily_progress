class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        int res_len=0;
        string res="";
        for(int i=0;i<n;i++)
        {

            // Odd length substring
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]) // Constraints . 
            {
                if(r-l + 1> res_len)//
                {
                    res_len=r-l+1;
                    res = s.substr(l, r - l + 1);
                }
                l--;
                r++;

            }

            // even length
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l + 1> res_len){
                    res_len=r-l+1;
                    res = s.substr(l, r - l + 1);
                }
                l--;
                r++;

            }
        }
        return res;

        
    }
};
/* Both loops are executed for each character in the string, and the appropriate loop is used based on the current position of the iterator. */