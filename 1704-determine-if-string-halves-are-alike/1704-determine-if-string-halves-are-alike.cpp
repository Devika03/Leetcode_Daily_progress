class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), cnt = 0;

        auto isVowel = [](char ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        for(int i=0; i<n/2; i++){
            if( isVowel(tolower(s[i])) ) cnt++;
            if( isVowel(tolower(s[i+n/2])) ) cnt--;  
        }

        return cnt == 0;
    }
};
