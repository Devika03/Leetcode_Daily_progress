class Solution {
public:
    int solve(int k,vector<int> &arr)
    {
        int ans=0;
        int start=0;
        int end=0;
        unordered_map<int,int>map1;
        int n=arr.size();
        while(end<n)
        {
            map1[arr[end]]++;
            while(start<=end && map1.size()>k)
            {
                map1[arr[start]]--;
                if(map1[arr[start]]==0)
                  map1.erase(arr[start]);
                start++;
            }
            //after coming out from while its ensured that map1.size()<=k
            ans+=(end-start+1);// (1 (2 (1 (1 (2 (1 1))))))  and k=2 ->total=7-1=end-start+1
            //but those are map.size()<=k  but we need only map.size()==k
            //   (k-1)(k)
            //<----
            //<---------
            //so req=ans(for <=k)-ans(for <=k-1)-->exactly ==k
            end++;
        }
        return ans; 
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) 
    {
        return solve(k,arr)-solve(k-1,arr);
    }
};
