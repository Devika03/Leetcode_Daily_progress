class Solution{
    private:
        int custom_lower_bound(vector<int>& v, int val){
            int left = 0, right = v.size() - 1;

            while (left < right)
            {
                int mid = left + (right - left) / 2;

                if(v[mid] < val){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            
            return left;
        }

    public:
        int lengthOfLIS(vector<int> nums){
            // write your code
            vector<int> v;

            for (auto num : nums){
                if(v.empty() || v.back() < num){
                    v.push_back(num);
                }else{
                    int idx = custom_lower_bound(v, num); // get the element which is greater than or equals to num
                    v[idx] = num; // replace that element with the current num
                }
            }
            
            return v.size();
        }
};
