class Solution {
public:
    int minimumDeletions(string s) {
      int cnt=0;
      int n=s.size();
      int ans=0;
      for(int i=0;i<n;i++)
      {
          if(s[i]=='b')
          {
              cnt++;
          }
          else
          {
              if(cnt>0)
              {
                ans++;
                cnt--;
              }
          }
      }
        return ans;
    }
};
