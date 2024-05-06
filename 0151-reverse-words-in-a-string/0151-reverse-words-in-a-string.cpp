#include <string>

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int i = 0;
        string result = "";
        while (i < len) {
            while (s[i] == ' ') {
                i++;
            }
            if (i >= len) break; // Exit loop if end of string is reached
            //else
            int j = i + 1;
            while (j < len && s[j] != ' ') {
                j++;
            }
            string word = s.substr(i, j - i);
            if (!result.empty()) {
                result = word + " " + result;
            } else {
                result = word;
            }
            i = j+1 ;
        }
        return result;
    }
};

/*
string reverseWords(string s) {
        string res = "";
        string temp = "";

        for (int i = 0; i < s.size(); ++i) {
            while (i < s.size() && s[i] != ' ') {
                temp += s[i];
                ++i;
            }

            if (temp != "") {
                // If we find a word, will add it at beginning of result.
                if (res != "") {
                    res = temp + " " + res;
                } else {
                    res = temp;
                }
                temp = "";
            }
        }
        return res;
    }
*/

/* 
In conclusion, the equivalent function to Java's String trim() in C++ is the std::trim() function */