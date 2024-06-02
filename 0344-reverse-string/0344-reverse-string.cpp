class Solution {
public:

    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(false); //makes the code run slightly faster
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<(j-i)){
            swap(s[i], s[j-i]);
            i++;

        }
        
        
    }
};