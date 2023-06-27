class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;
        
        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        pq.push({0, 0});
        
        while (k > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            
            ans.push_back({nums1[i], nums2[j]});
            
            if (i + 1 < nums1.size())
                pq.push({i + 1, j});
            
            if (i == 0 && j + 1 < nums2.size())
                pq.push({i, j + 1});
            
            k--;
        }
        
        return ans;
    }
};
;