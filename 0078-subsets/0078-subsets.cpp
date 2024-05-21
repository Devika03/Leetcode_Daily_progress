class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int n = nums.size();
        for(int i=0; i< 1<<n; i++) {
            
            int t = i;
            vector<int> st;
            
            for (int j=0; j<n; j++) {
                
                if ((t >> j) & 1) {
                    st.push_back(nums[j]);
                }   
            }
            ans.push_back(st);
        }
        
        return ans;
    }
};