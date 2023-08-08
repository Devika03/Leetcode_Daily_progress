class Solution {
public:
    int search(vector<int>& nums, int target) {
        int v=-1;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)==target){
                v=i;
                break;
            }
        }
        return v;
    }
};