class Solution {
public:


    int findLongestChain(vector<vector<int>>& pairs) {
        //sort 
        vector<int> temp;
        for(int i=0; i<pairs.size(); i++) {
            for(int j=i+1; j<pairs.size(); j++) { 
                if(pairs[i][1] > pairs[j][1]) {
                    temp = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = temp;
                }
            }
        }

        // count
        int count = 1;
        int i = 0, j = 1;
        while ( j < pairs.size() ) {
            if (pairs[j][0] > pairs[i][1]) {
                count++;
                i = j;
            } 
            j++;
        }
        return count;
    }
};