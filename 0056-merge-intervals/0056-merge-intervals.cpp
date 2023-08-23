class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        vector<vector<int>>result;
        int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++)
    {
        if(ans.empty() || v[i][0]>ans.back()[1]) // ans.back() reference to last added vector. 
        ans.push_back(v[i]);
        else
        ans.back()[1]=max(ans.back()[1],v[i][1]);
    }
    return ans;
    }
};