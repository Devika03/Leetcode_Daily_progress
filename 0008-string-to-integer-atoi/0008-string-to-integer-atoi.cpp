/*class Solution {
public:
    int myAtoi(string s) 
    {
        string result = "";
        int result_int = 0;
        int flag = 0;//For no sign and "+"
        for(int i = 0 ; i<s.size() ; i++)
        {
            while(s[i] == ' ')
            {
                i++;
            }
            
            if(s[i]=='-') 
            {
                flag=1;
                i++;
            }
            while(s[i]=='0')
            {
                i++;
            }
            if(i!=s.size())
            {
                result =result+s[i];
            }
            
            result_int = stoi(result);
                        
        }
        if(flag==1)
        {
            result_int = -result_int;
        }
         return result_int; 
    }
};*/

#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long result_int = 0; // Change int to long long
        int flag = 1; // Initialize flag to 1 for default positive sign
        int i = 0;

        // Skip leading spaces
        while (s[i] == ' ') {
            i++;
        }

        // Check for optional sign
        if (s[i] == '-') {
            flag = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Accumulate digits
        while (isdigit(s[i])) {
            result_int = result_int * 10 + (s[i] - '0');
            // Check for out-of-range condition
            if (flag == 1 && result_int > INT_MAX) {
                return INT_MAX;
            } else if (flag == -1 && -result_int < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        // Apply sign
        result_int *= flag;

        return static_cast<int>(result_int);
    }
};


