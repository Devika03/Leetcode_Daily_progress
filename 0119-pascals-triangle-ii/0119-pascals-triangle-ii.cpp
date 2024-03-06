class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>>res;
        for(int i = 0 ; i<rowIndex+1 ; i++)//0th Index.
        {
            vector<int>stepvec(i+1,1);//Consider you are at i=2 [1,1,1].
            for(int j =1 ; j<i; j++)//As j=0th and j=(i+1)th ele. is set to 1. 
            {
                stepvec[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(stepvec);
        }
        return res[rowIndex];
    }
};
