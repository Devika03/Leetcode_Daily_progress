class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int left = 0;
        bool minFound = false, maxFound = false;
        int minIndex=0,maxIndex=0;
        for (int right = 0; right < n; right++) {
            if (nums[right] > maxK || nums[right] < minK) {
                left = right + 1;
                maxFound = false;
                minFound = false;
            }
            if (nums[right] == maxK) {
                maxFound = true;
                maxIndex=right;
            }
            if (nums[right] == minK) {
                minFound = true;
                minIndex=right;
            }
            if (maxFound && minFound) {
                int index=min(minIndex,maxIndex);
                count += (index - left + 1);
            }
        }

        return count;
    }
};
