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
#include <string>

class Solution {
public:
    int repeatedStringMatch(string n1, string n2) {
        string final_string = n1;
        int count = 1;
        int len_n1 = n1.size();
        int len_n2 = n2.size();

        // Calculate the number of concatenations needed to ensure final_string has at least len_n2 characters
        int numConcatenations = (len_n2 + len_n1 - 1) / len_n1;

        // Concatenate n1 the required number of times
        for (int i = 1; i < numConcatenations; i++) {
            final_string += n1;
            count++;
        }

        // Check if n2 is a substring of final_string
        if (final_string.find(n2) != string::npos) {
            return count;
        }

        // If n2 is not a substring yet, concatenate n1 one more time
        final_string += n1;
        count++;

        if (final_string.find(n2) != string::npos) {
            return count;
        }

        // If still not found, return -1
        return -1;
    }
};



