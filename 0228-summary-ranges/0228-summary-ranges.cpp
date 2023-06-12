class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
         
        
        vector <string> res;

        if(nums.size() == 0) return res;
        if(nums.size() == 1) return {to_string(nums[0])};
        
        int start = nums[0];
        int end = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                end = nums[i];
            }

            if(nums[i] != nums[i-1]+1){
                if(start == end){
                    res.push_back(to_string(start));
                }

                else{
                    string exp = to_string(start)  + "->" + to_string(end);
                    res.push_back(exp);
                }
                start = nums[i];
                end = nums[i];
            }
        }

        if(start == end){
                res.push_back(to_string(start));
            }

            else{
                string exp = to_string(start)  + "->" + to_string(end);
                res.push_back(exp);
            }


        return res;
    }
};