class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> t(101,0);
        //vector initialized to count the frequency
        for(int i=0;i<nums.size();i++){
            t[nums[i]]++;
        }
        
        int m = -1,c=0;
        //m for max count of frequency and c is the count of those numbers having max count
        for(int i=0;i<=100;i++){
            if(t[i]){
                if(m<t[i]){
                    m=t[i];
                    c=1;
                }
                else if(m==t[i]){
                    c++;
                }
            }
            
        }
        //total frequency will be m*c
        return m*c;
    }
};