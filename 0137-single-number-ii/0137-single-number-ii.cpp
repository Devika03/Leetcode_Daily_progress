class Solution {
public:
    int singleNumber(vector<int>& nums) {

       int couti=0,ans=0;

//This for loop is to find 1 at i-th position

       for(int i=0;i<32;i++)

       {
           couti=0;
//This for loop is iterating over every number of array
           for(int j=0;j<nums.size();j++){

           if((nums[j]>>i)&1==1)

           couti++;

           }

             couti%=3;

       if(couti!=0)

       ans|=couti<<i;

       }
       return ans;
    }
  
};