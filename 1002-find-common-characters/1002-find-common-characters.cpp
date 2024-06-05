class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        map<char, int> m2;
        
        for(char ch : words[0]){
            m2[ch]++;
        }
        
        for(int i = 1; i < words.size(); i++){
            map<char,int> m1;
            for(char ch : words[i]){
                m1[ch]++;
            }
            
            for(auto it = m2.begin(); it != m2.end();){
                if(m1.find(it->first) != m1.end()){
                    it->second = min(it->second, m1[it->first]);
                    ++it;
                } else {
                    it = m2.erase(it);
                }
            }
        }
        
        for(auto it : m2){
            string ch(1, it.first);
            int x = it.second;
            while(x--){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};