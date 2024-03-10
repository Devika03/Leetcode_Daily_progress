/*class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i = 1 ; i<n ; i++)
        {
            if(v[i][0]<=v[i-1][1])
            {
                v[i][0]=v[i-1][0];
                v.erase(v.begin()+i-1);
            }
        }
        return v;
    }
};*/
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the start time
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (merged.back()[1] >= intervals[i][0]) {
                // Merge overlapping intervals
                merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
            } else {
                // Add new interval to the merged list
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

















/*vector<vector<int>>result;
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
*/