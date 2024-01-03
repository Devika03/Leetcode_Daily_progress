class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0 , prev = 0;
        for(string s : bank){
            int count = 0;
            for(char c : s){
                if(c == '1'){
                    count++;
                }
            }
            if(count > 0){
                result += prev * count;
                prev = count;
            }
        }
        return result;
    }
};