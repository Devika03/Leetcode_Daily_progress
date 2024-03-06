/* i=0 [1]  here ,j=0 (A relation b/w i and j )
   i=1 [1,1]      j=0,1
   i=2 [1,2,1]    j=0,*1*,2
   i=3 [1,3,3,1] */

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>res;
        for(int i = 0 ; i<numRows ; i++)
        {
            vector<int>stepvec(i+1,1);//Consider you are at i=2 [1,1,1].
            for(int j =1 ; j<i; j++)//As j=0th and j=(i+1)th ele. is set to 1. 
            {
                stepvec[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(stepvec);
        }
return res;
}
};
