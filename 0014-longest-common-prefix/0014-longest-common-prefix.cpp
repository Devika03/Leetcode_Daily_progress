class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin() , strs.end());
        string result = "";
        if (strs.empty()) 
        {
            return result; // Return empty string for empty input
        }
        int n = strs.size();
        string first_word= strs[0];
        string last_word= strs[n-1];
        int size_first_word = first_word.size();
        int size_last_word = last_word.size();
        int min_size = min(size_first_word, size_last_word);
        for(int i = 0 ; i< min_size ; i++ )
        {
            if(first_word[i]==last_word[i])
            {
                result = result+first_word[i];
            }
            else
            {
                break;
            }
        }
        return result;
        
        
    }
    };