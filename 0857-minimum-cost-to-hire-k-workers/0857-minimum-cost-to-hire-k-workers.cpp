class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();     
        vector<pair<double, int>> ratio;

        for(int i = 0; i < n; i++)
            ratio.push_back({(double) wage[i] / quality[i], i});
        
        sort(ratio.begin(), ratio.end());
        int qualitySum = 0;
        double maxRate = 0.0;

        priority_queue<int> maxi;
        for(int i = 0; i < k; i++) {
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            maxi.push(quality[ratio[i].second]);
        }

        double res = maxRate * qualitySum;
        for(int i = k; i < n; i++) {
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= maxi.top();
            maxi.pop();

            qualitySum += quality[ratio[i].second];
            maxi.push(quality[ratio[i].second]);
            res = min(res, maxRate * qualitySum);
        }

        return res;
    }
};