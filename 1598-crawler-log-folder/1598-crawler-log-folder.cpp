class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(int i=0;i<logs.size();i++)
        {
            string dir=logs[i];
            if(dir[0]=='.' && dir[1]=='/')
                continue;
            else if(dir[0]!='.')
                ans++;
            else
            {
                if(ans!=0)
                    ans--;
            }
        }
        return ans;
    }
};