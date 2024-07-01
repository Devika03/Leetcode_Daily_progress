class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        int index = -1;
        for(int i = 0; i < arr.size(); i++) {
            if(cnt == 3) {
                return true;
            }
            else if(index == -1 && arr[i] % 2 != 0) {
                cnt++;
                index = i;
            }
            else if(arr[i] % 2 != 0 && i == index + 1) {
                cnt++;
                index = i;
            }
            else {
                cnt = 0;
                index = -1;
            }
        }
        if(cnt == 3) {
            return true;
        }
        return false;
    }
};