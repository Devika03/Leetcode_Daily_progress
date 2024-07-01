class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int currFlipCount = 0;
        int n = nums.size();
        vector<bool> vec(n,false);             // to keep a track of all flips along with their index
        int res = 0;

        for(int i=0; i<n; i++){
            if(i >= k && vec[i-k]==true){      // prev flip out of range of curr index
                currFlipCount--;
            }
            if(currFlipCount%2 == nums[i]){    // currFlip == odd && nums[i] == 1 (Flip needed)
                                               // currFlip == even && nums[i] == 0 (Flip needed)
                    
                    if(i+k <= n){              // check subarray of k possible or not
                        currFlipCount++;
                        vec[i] = true;
                        res++;
                    }
                    else
                        return -1;

            }
        }
        return res;
    }
};