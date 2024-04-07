class Solution {
public:
    bool checkValidString(string s) {
        stack<int>p;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                p.push(i);
            }
            else if(s[i]==')'&&!p.empty()){
                s.erase(s.begin()+p.top(),s.begin()+p.top()+1);
                i=i-1;
                s.erase(s.begin()+i,s.begin()+i+1);
                i=i-1;
                p.pop();
            }
        }
        stack<int>po;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                po.push(i);
            else if(s[i]=='*'&&!po.empty()){
                s.erase(s.begin()+po.top(),s.begin()+po.top()+1);
                i=i-1;
                s.erase(s.begin()+i,s.begin()+i+1);
                i=i-1;
                po.pop();
            }
        }
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*')
                st.push(i);
            else if(s[i]==')'&&!st.empty()){
                s.erase(s.begin()+st.top(),s.begin()+st.top()+1);
                i=i-1;
                s.erase(s.begin()+i,s.begin()+i+1);
                i=i-1;
                st.pop();
            }
        }

        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]==')')
                return false;
        }
        return true;
    }
};