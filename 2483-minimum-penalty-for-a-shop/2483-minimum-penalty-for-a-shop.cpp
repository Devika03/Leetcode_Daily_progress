class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();

        int min_ind = 0, min_penal = INT_MAX;
    //prefix sum of N and suffix sum of Y    
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;i++){
            if(c[i] == 'Y'){
                preSum[0]++;
            }
        }

        min_penal = preSum[0];
        for(int i=1;i<=n;i++){
          preSum[i] = preSum[i-1];
            if(c[i-1] == 'Y'){
                preSum[i]--;
            } 
            else preSum[i]++;

            if(preSum[i] < min_penal){
                min_penal = preSum[i];
                min_ind = i;
            }
        }

        return min_ind;
    }
};