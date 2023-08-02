class Solution {
public:
    int used[25] = {};

    void Try(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if(used[j] == 0)
            {
                used[j] = 1;
                tmp.push_back(nums[j]);
                if(tmp.size() == nums.size()) res.push_back(tmp);
                else if(tmp.size() < nums.size()) Try(nums, tmp, res);
                tmp.pop_back();
                used[j] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        Try(nums, tmp, res);
        return res;
    }
};