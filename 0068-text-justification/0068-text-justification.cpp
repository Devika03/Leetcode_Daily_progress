class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for(int i=0;i<words.size();){
            int x=words[i].size();
            int j=i+1,l=0;
            while(x<maxWidth && j<words.size()){
                if(x+1+words[j].size()<=maxWidth){
                    x=x+1+words[j].size();
                    j++;
                    l++;
                }
                else
                    break;
            }
            string s;
            s+=words[i++];
            if(j==words.size()){
                while(i<words.size())
                    s=s+' '+words[i++];
            }
            else{
                if(l){
                    int a=maxWidth-x;
                    int b=a/l,c=a%l;
                    while(i<j){
                        string space(b+1,' ');
                        if(c){
                            space+=' ';
                            c--;
                        }
                        s+=space;
                        s+=words[i++];
                    }
                }
            }
            while(s.size()!=maxWidth)
                s+=' ';
            ans.push_back(s);
        }
        return ans;
    }
};