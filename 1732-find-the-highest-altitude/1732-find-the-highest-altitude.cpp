class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, prev = 0;
        for(int i=0; i<gain.size(); i++){
            prev += gain[i];
            ans = max(ans, prev);
        }
        return ans;
    }
};