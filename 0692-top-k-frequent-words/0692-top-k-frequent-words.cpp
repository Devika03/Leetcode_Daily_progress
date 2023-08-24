class Solution {
    static bool cmp(pair<string,int>p1 ,pair<string,int>p2)
    {
        if(p1.second > p2.second || p1.second==p2.second && p1.first< p2.first/*Lexico. check*/)
        return true;//It means p1 and p2 are in correct position . No interchange reqd. 
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp; //To create the Map and store the freq.
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        vector<pair<string ,int>> v(mp.begin(),mp.end());//Init. v w/ the contents of mp.
        sort(v.begin(),v.end(),cmp);//Sorts Lexico.
       
        vector<string> ans;
       for(int i=0;i<k;i++)
       {
           ans.push_back(v[i].first);
       }
        return ans;
    }
};