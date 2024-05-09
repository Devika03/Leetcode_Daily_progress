/*class Solution {
public:
    int repeatedStringMatch(string n1, string n2) 
    {
        string final_string = n1; int count = 1;
        int len_n1 = n1.size();
        int len_n2 = n2.size();
        int r = len_n1/len_n2; 
        for(int i = 0 ; i< r+2 ; i++)
        {
            if(n1.find(n2)!=-1)//n2 is already a substring of n1 . 
            {
                return count;
            }
            else
            {
                final_string+= n1; 
                count++;
            }
                
        }
        return -1;
    }
};*/
#include<string.h>
class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        string final_result = a;
        int count = 1;
        int len_n1 = a.size();
        int len_n2 = b.size();
        

        while(final_result.size()<len_n2)
        {
            final_result+=a;
            count++;
        }

        if(final_result.find(b)!= string::npos)//If found 
        {
            return count;
        }

        //If not yet , We still add 1 more . 
        final_result+=a;
        count++;
        
        if(final_result.find(b)!= string::npos)
        {
            return count;
        }
        
        return -1;
    }
};