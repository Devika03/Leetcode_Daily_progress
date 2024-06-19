class Solution {
    bool isPossible(vector<int>& bloomDay, int m, int k , int d){
       int cnt = 0;
       for(int x:bloomDay){
            if(x <= d){
                if(++cnt == k){
                     if(!--m) return true;
                     cnt = 0;
                }
            }
            else cnt = 0;
       }
       return false;   
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > bloomDay.size()) return -1;
        int s = INT_MAX , e = INT_MIN , mid , ans = -1;
        for(int x:bloomDay){
            if(x < s) s = x;
            if(x > e) e = x;
        }
        while(s <= e){
            mid = s + (e - s)/2;
            if(isPossible(bloomDay , m , k , mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};