class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long>mp;
        mp[0] = 1;
         long long prefixpattern = 0, ans = 0;
        for(auto ch: word){
            prefixpattern = (prefixpattern) ^ (1 << (ch - 'a'));
            ans += mp[prefixpattern];

            for(char k = 'a'; k <= 'j'; k++){
                long long oddpattern = (prefixpattern) ^ (1 << (k - 'a'));
                ans += mp[oddpattern];
            }
            mp[prefixpattern]++;
        }
        return ans;
    }
};