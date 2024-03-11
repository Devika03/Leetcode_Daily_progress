class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> new_merged;
        new_merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (new_merged.back()[1] >= intervals[i][0]) {
                // Merge overlapping intervals
                new_merged.back()[1] = max(new_merged.back()[1], intervals[i][1]); // Consider a case of [1,4],[2,3] = [1,4] ; [1,3],[2,4] = [1,4]
            } else {
                // Add new interval to the merged list
                new_merged.push_back(intervals[i]);
            }
        }

        return new_merged;
    }
};