class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int prev=0;
        int ans=0;
        sort(intervals.begin(),intervals.end());
for(int i=1;i<intervals.size();i++){
    if(intervals[prev][1]>intervals[i][0]){
        ans++;
        if(intervals[i][1]<=intervals[prev][1]){
            prev=i;

        }
    }
    else{
        prev=i;
    }
}
        return ans;
        
    }
};