class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        unordered_map<string,int>User_countofwords;
         
        
        for(int i = 0 ; i<senders.size() ; i++)
        {
            int count = 0 ;
            string word;
            
            stringstream ss(messages[i]);
            while(ss>>word)
            {
                count++;
            }
            User_countofwords[senders[i]]+=count;     
        }
        
        string largest_sender = "";
        int max_word_count = 0;
        
        for ( auto it : User_countofwords) 
        {
            if (it.second > max_word_count ||  (it.second == max_word_count && it.first > largest_sender)) 
            {
                max_word_count = it.second;
                largest_sender = it.first;
            }
        }
        
        return largest_sender;
        
        
        
    }
};