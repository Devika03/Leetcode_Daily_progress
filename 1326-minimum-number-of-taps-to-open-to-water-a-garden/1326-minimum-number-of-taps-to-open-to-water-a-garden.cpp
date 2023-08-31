class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1, 0);
        
        for(int i = 0; i<ranges.size(); i++) 
        {
            
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);
            
            arr[start] = max(arr[start], end);
            
        }
        
        int taps     = 0;
        int currEnd  = 0;
        int maxEnd   = 0;
        
        for(int i = 0; i<n+1; i++) 
        {
            
            if(i > maxEnd)
                return -1;
            
            if(i > currEnd) 
            {
                taps++;
                currEnd = maxEnd;
            }
            
            maxEnd = max(maxEnd, arr[i]);
            
        }
        
        return taps;    
    }
};