#include<string.h>

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        int s_len = s.size();
        int t_len = t.size();
        bool flag = true;
        if(s_len!=t_len)
        {
            return false;
        }
        else
        {
            for( int i = 0 ; i < t_len ; i++)
            {
                if(s.find(t[i])!=string::npos)
                {
                    s.erase(s.find(t[i]),1);
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};