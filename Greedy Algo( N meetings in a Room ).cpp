//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    struct meeting {
        int start;
        int end;
        int index;
    };
    bool cmp (struct meeting m1 , meeting m2 )
    {
        if(m1.end<m2.end)return true;
        if(m1.end== m2.end && m1.index < m2.index )return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i =0 ; i<n ;i++)
        {
            meet[i].start=start[i] , meet[i].end=end[i] , meet[i].index=i+1;
        }
        sort(meet , meet+n , cmp);
        
        int endlimit = meet[0].end;
        vector<int>ans;
        ans.push_back(meet[0].index);
        
        for(int i =1;i<n;i++)
        {
            if(meet[i].start>endlimit) 
            {
            endlimit = meet[i].end;
            ans.push_back(meet[i].index);
            }
            continue;
        }
        for(int i =0;i<answer.size();i++)
        {
            cout<<answer[i]<<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends