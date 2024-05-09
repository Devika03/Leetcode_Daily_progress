#include<string.h>
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if ( haystack.find(needle) != string::npos )
        {
            return haystack.find(needle);
        }
        else 
            return -1;
    }
    
};

/*
int n1 = haystack.size();//9
        int n2 = needle.size();//3
        
        if (n2>n1) return -1; // Corner case .
        
        for (int i = 0; i < n1-n2+1; i++)//haystack
        {
            if(haystack.substr(i,n2)==needle) { return i; }//substr with start index = i and end index = n2.
        }
            return -1; // needle not found
*/