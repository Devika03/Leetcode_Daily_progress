class Solution {
public:
    int specialArray(vector<int>& arr) {
        int n=arr.size();
        
        int maxi=0;
        int count=0;
        
        for(int i=0;i<=n-1;i++)
        {
        
           
            if(arr[i]>maxi) maxi=arr[i];
        }
        vector<int> hash(maxi + 1, 0);

         for(int i=0;i<=n-1;i++)
        {
        
           hash[arr[i]]+=1;
            
        }
        for(int i=maxi;i>=0;i--)
        {
            count+=hash[i];
            if(i==count)
            return count;
        }
        return -1;
        
    }
};