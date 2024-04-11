class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.length();
        if(n==k){
            return "0";
        }
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            while( !st.empty() && st.top()>s[i] && k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while (i<ans.length() && ans[i]=='0') {
            i++;
        }
        ans=ans.substr(i);
        if (ans.empty()){
            return "0";
        }
        
        return ans;
    }
};