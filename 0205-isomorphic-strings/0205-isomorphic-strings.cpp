class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<char>v(256,0);
        vector<bool>vv(256,false);
        for(int i=0; i<s.size();i++){
            if(v[s[i]]==0 && vv[t[i]]==false){
                v[s[i]]=t[i]; 
                vv[t[i]]=true;
            }
            else{
                if(v[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};