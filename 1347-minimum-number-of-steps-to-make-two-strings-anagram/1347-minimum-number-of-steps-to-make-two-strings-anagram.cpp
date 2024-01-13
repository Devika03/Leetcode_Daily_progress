class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> frequency(26,0);
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            frequency[s[i]-'a']++;
            frequency[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(frequency[i]>0)
            {
                ans=ans+frequency[i];
            }
        }
        return ans;
    }
};