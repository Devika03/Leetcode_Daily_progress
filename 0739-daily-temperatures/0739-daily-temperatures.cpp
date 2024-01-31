class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        for(int i = n-2; i > -1; i--){
            int j = i + 1;
            while(j < n){
                if(temp[i] < temp[j]){
                    ans[i] = j-i;
                    break;
                }else{
                    if(ans[j] == 0){
                        break;
                    }
                    j = j + ans[j];
                }
            }
        }
        return ans;
    }
};
