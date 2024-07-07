class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int>ans;
        
        vector<int>hash(26,0);
        vector<int>p_hash(26,0);
        
        int size_s=s.size();
        int size_p=p.size();
        
        if(size_s<size_p) return ans;
        
        int start=0 ; int end = 0 ; 
        while(end<size_p)
        {
            p_hash[p[end]-'a']++;
            hash[s[end]-'a']++;
            
            end++;
        }
        end--;
        
        while(end<size_s)
        {
            if(p_hash==hash) ans.push_back(start);
            end++;
            if(end!=size_s) hash[s[end]-'a']++;
            
            hash[s[start]-'a']--;
            start++;
        }
        return ans;
    }
};


//TLE :-
//  bool isAnagram(string s, string t) //t , s .
//     {
//         if(s.size()<t.size()) return false;
//         unordered_map<char,int>char_count_s;
//         unordered_map<char,int>t_char_count;
//         for(int i = 0 ; i<s.size() ; i++)
//         {
//             if(char_count_s.find(s[i])==char_count_s.end())
//             {
//                 char_count_s[s[i]]=1;
//             }
//             char_count_s[s[i]]++;            
//         }
        
//         for(int i = 0 ; i<t.size() ; i++)
//         {
//             if(t_char_count.find(t[i])==t_char_count.end())
//             {
//                 t_char_count[t[i]]=1;
//             }
//             t_char_count[t[i]]++;            
//         }
//         bool t_is_anagram = true;
//         for(auto it:char_count_s)
//         {
//             if(t_char_count.find(it.first)!=t_char_count.end() && char_count_s[it.first]==t_char_count[it.first])
//             {
//                 continue;
//             }
//             else
//             {
//                 t_is_anagram=false;
//                 break;
//             }
//         }
//         return t_is_anagram; 
        
        
//     }
    
    
//     vector<int> findAnagrams(string s, string p) 
//     {
//         vector<int>start_index;
//         int size_p = p.size();//3
//         int size_s = s.size();//10
        
//         int start= 0;//0
//         int end = start+size_p;//0+3 = 4th char.
        
//         for(int i = 0 ; i<=size_s-size_p ; i++)
//         {
             
//             string substr = s.substr(i, size_p);
            
//             if(isAnagram(substr,p)==true) start_index.push_back(i);
            
//         }
//         return start_index;
        
        
//     }