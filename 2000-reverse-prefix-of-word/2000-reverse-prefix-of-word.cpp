class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.length(); ++i) {
            if(word[i] == ch) {
                reverse(word, 0, i);
                break;
            }
        }
        return word;
    }

    void reverse(string& s, int i, int j) {
        int start = i, end = j;
        while(start<end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};