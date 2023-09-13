class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1)
        return 1;

        int n = ratings.size();
        int ans = 0;
        vector<int>candies(n,1);//intialise candies with 1 at minimum for all children
        //Left to Right  Traversal of the vector
        for(int i=1;i<n;i++)
        {
          if(ratings[i] > ratings[i-1] && candies[i] <= candies[i-1])
          {
            candies[i] = candies[i-1]+1;
          } 
        }   
        //right to Left traversal of Vector
         for(int i=n-2;i >=0;i--)
        {
          if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
          {
            candies[i] = candies[i+1]+1;
          } 
        } 

        //calculating the total sum of Candies
        for(int i=0;i<n;i++)
        {
          ans+=candies[i];
        } 
        return ans;
   }
};