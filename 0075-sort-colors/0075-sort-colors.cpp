class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int count0 =0 ;
        int count1 =0 ;
        int count2 = 0;
        for(int i =0 ; i<nums.size();i++)
        {
            if(nums[i]==0) count0++;
            else if(nums[i]==1) count1++;
            else if(nums[i]==2) count2++;
        }
        for (int i0=0; i0<count0 ; i0++)
        {
            nums[i0]=0;
        }
        for( int i1= count0 ; i1<count0+count1 ; i1++)
        {
            nums[i1]=1;
        }
        for(int i2= count0+count1 ; i2<count0+count1+count2 ; i2++)
        {
            nums[i2]=2;
        }
    }
};


