class Solution {
public:
    void split(vector<string>& helper,string sentence){
        string temp="";
        for(char i:sentence){
            if(i!=' '){
                temp+=i;
            }
            else{
                helper.push_back(temp);
                temp="";
            }
        }
        helper.push_back(temp);
        return;
    }
    string join(vector<string>& helper,string sentence){
        for(int i=0;i<helper.size();i++){
            sentence=sentence+helper[i]+" ";
        }
        sentence.pop_back();
        return sentence;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> helper;
        split(helper,sentence);
        set<string> st;
        int j=helper.size();
        for(string i:dictionary)st.insert(i);
        for(int i=0;i<j;i++){
            int l=1;
            while(l<=helper[i].length()){
                if(st.find(helper[i].substr(0,l))!=st.end()){
                    helper[i]=helper[i].substr(0,l);
                    break;
                }
                l++;
            }
        }
        return join(helper,"");
    }
};