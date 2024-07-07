class Solution {
public:

    // same problem as "Count occurences of anagrams"

    vector<int> findAnagrams(string s, string p) {
        int i = 0, j = 0;
        int k = p.length();
        unordered_map<char, int> map;
        vector<int>ans;
        
        // creating a "count map" from pattern
        for (int i = 0; i < k; i++) {
            map[p[i]]++;
        }
        
        int count = map.size(); // Keeps track of distinct letters
        int n = s.length();
        
        while (j < n) {
            char ch = s[j];
            if (map.find(ch) != map.end()) {
                map[ch]--;
                if (map[ch] == 0) {
                    count--;
                }
            }
            
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                if (count == 0) {
                    ans.push_back(i);
                }
                if (map.find(s[i]) != map.end()) {
                    map[s[i]]++;
                    if (map[s[i]] == 1) {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};



// TLE :-
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