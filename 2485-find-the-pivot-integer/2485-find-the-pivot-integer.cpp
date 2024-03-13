
class Solution {
public:
    int pivotInteger(int n) {
        int sum =0;
        int temp = 0;
        for(int i = n;i>0;i--){
            sum += i;
            temp = (i*(i+1))/2;
            if(sum==temp){
                return i;
            }
        }
        return -1;
    }
};