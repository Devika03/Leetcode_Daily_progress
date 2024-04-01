class Solution {
public:
    int lengthOfLastWord(string s) {

        int len = 0;
        int itr = s.length() - 1;

        while(s[itr] == ' ' && itr >= 0) itr--;

        for(int i=itr;i>=0;i--){

            if(s[i] == ' ') break;
            len ++;

        }

        return len;

    }
};