class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int n = n1+n2;
        int index1 = n/2;
        int index2 = index1-1;
        int count = 0 ; 
        
        int val1 = -1; 
        int val2 = -1;
        
        int i = 0 ; int j = 0 ; 
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                if(count==index1) val1 = nums1[i];
                if(count==index2) val2 = nums1[i];
                
                count++;
                i++;
                
            }
            else
            {
                if(count==index1) val1 = nums2[j];
                if(count==index2) val2 = nums2[j];
                
                count++;
                j++;
            }
        }
        //Left-Over elements of either of the 2 arrays : 
        while (i < n1) 
        {
            if (count == index1)val1 = nums1[i];
            if (count == index2)val2 = nums1[i];
            count++;
            i++;
        }
        while (j < n2) 
        {
            if (count == index1)val1 = nums2[j];
            if (count == index2)val2 = nums2[j];
            count++;
            j++;
        }
        if(n%2 != 0) return val1;
        else return (double)(val1+val2)/2;
        
    
    }
};













// int n1=nums1.size();
//         int n2=nums2.size();
        
//         int count_ptr=0;
        
//         int i=0,j=0;
        
//         int n=n1+n2;
        
//         int mid_right=n/2;
//         int mid_left=mid_right-1;
        
//         int val1_at_mid_right=-1,val2_at_mid_left=-1;
        
//         while(i<n1 && j<n2)
//         {
//             if(nums1[i]<nums2[j])
//             {
//                 if(count_ptr==mid_left)val1_at_mid_right=nums1[i];
//                 if(count_ptr==mid_right)val2_at_mid_left=nums1[i];
//                 count_ptr++;
//                 i++;
//             }
//             else{
//                 if(count_ptr==mid_left)val1_at_mid_right=nums2[j];
//                 if(count_ptr==mid_right)val2_at_mid_left=nums2[j];
//                 count_ptr++;
//                 j++;
//             }
            
//         }
//         while (i < n1) 
//         {
//         if (count_ptr == mid_left)val1_at_mid_right = nums1[i];
//         if (count_ptr == mid_right)val2_at_mid_left = nums1[i];
//         count_ptr++;
//         i++;
//         }
//     while (j < n2) {
//         if (count_ptr == mid_left)val1_at_mid_right = nums2[j];
//         if (count_ptr == mid_right)val2_at_mid_left = nums2[j];
//         count_ptr++;
//         j++;
//     }
//     if(n%2==0){
//         return (double)(val1_at_mid_right+val2_at_mid_left)/2;
//     }else{
//         return val2_at_mid_left;
//     }

//         return -1;
    

/*
Naive Approach : 
{
        double median = 0;
        vector<int>result;
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            result.push_back(nums1[i]);
        }
        for(int i = 0 ; i<nums2.size() ; i++)
        {
            result.push_back(nums2[i]);
        }
        sort(result.begin(),result.end());
        
        if(result.size()%2==0)
        {
            int left = 0 ; 
            int right = result.size()-1;
            int index_1 = ( left + right ) / 2;
            int index_2 = index_1 +1 ; 
            return (result[index_1] + result[index_2])/2.0;
        }
        else{
            int left = 0 ; 
            int right = result.size()-1;
            int index_1 = ( left + right ) / 2.0;
            return result[index_1];
        }
        
    }
    */