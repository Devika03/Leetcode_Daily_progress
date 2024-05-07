class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I'] =1;
        mp['V'] =5;
        mp['X'] =10;
        mp['L'] =50;
        mp['C'] =100;
        mp['D'] =500;
        mp['M'] =1000;

        int sum =0;
        for(int i =0; i<s.size()-1; i++)
        {
            auto it1 =mp.find(s[i]);
            auto it2 =mp.find(s[i+1]);

            if(it1->second>=it2->second)
            {
                sum+=it1->second;
            }
            else
            {
                sum-=it1->second;
            }

        }
        sum+= mp[s[s.size()-1]];

        return sum;
    }
};
// Create a string of size n and fill
// the string with character x.
//string s(size_t n, char x);