class Solution {
public:
    int solve(vector<int> &arr){
        int n=arr.size(),maxi=0;
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            int diff=(right[i]-left[i]-1)*(arr[i]);
            maxi=max(maxi,diff);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0; j<m; j++){
            dp[0][j]=matrix[0][j]-'0';
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int chk=solve(dp[i]);
            ans=max(ans,chk);
        }
        return ans;
    }
};