class Solution 
{
public:
    bool isAnagram(string s, string t) //t , s .
    {
        if(s.size()<t.size()) return false;
        unordered_map<char,int>char_count_s;
        unordered_map<char,int>t_char_count;
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(char_count_s.find(s[i])==char_count_s.end())
            {
                char_count_s[s[i]]=1;
            }
            char_count_s[s[i]]++;            
        }
        
        for(int i = 0 ; i<t.size() ; i++)
        {
            if(t_char_count.find(t[i])==t_char_count.end())
            {
                t_char_count[t[i]]=1;
            }
            t_char_count[t[i]]++;            
        }
        bool t_is_anagram = true;
        for(auto it:char_count_s)
        {
            if(t_char_count.find(it.first)!=t_char_count.end() && char_count_s[it.first]==t_char_count[it.first])
            {
                continue;
            }
            else
            {
                t_is_anagram=false;
                break;
            }
        }
        return t_is_anagram; 
        
        
    }
};




// int s_len = s.size();
//         int t_len = t.size();
//         bool flag = true;
//         if(s_len!=t_len)
//         {
//             return false;
//         }
//         else
//         {
//             for( int i = 0 ; i < t_len ; i++)
//             {
//                 if(s.find(t[i])!=string::npos)
//                 {
//                     s.erase(s.find(t[i]),1);
//                     continue;
//                 }
//                 else
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//         }
//         return flag;