// class Solution 
// {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
//     {
//         double median = 0;
//         vector<int>result;
//         for(int i = 0 ; i<nums1.size() ; i++)
//         {
//             result.push_back(nums1[i]);
//         }
//         for(int i = 0 ; i<nums2.size() ; i++)
//         {
//             result.push_back(nums2[i]);
//         }
//         sort(result.begin(),result.end());
        
//         if(result.size()%2==0)
//         {
//             int left = 0 ; 
//             int right = result.size()-1;
//             int index_1 = ( left + right ) / 2;
//             int index_2 = index_1 +1 ; 
//             median = (result[index_1] + result[index_2])/2;
//         }
//         else{
//             int left = 0 ; 
//             int right = result.size()-1;
//             int index_1 = ( left + right ) / 2;
//             median = result[index_1];
//         }
        
//         return median;
        
//     }
// };



#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> merged;
        int i = 0, j = 0;
        
        // Merge the two sorted arrays into the merged vector
        while (i < nums1.size() && j < nums2.size()) 
        {
            if (nums1[i] < nums2[j]) 
            {
                merged.push_back(nums1[i]);
                i++;
            } 
            else 
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        // Append any remaining elements from nums1
        while (i < nums1.size()) 
        {
            merged.push_back(nums1[i]);
            i++;
        }
        
        // Append any remaining elements from nums2
        while (j < nums2.size()) 
        {
            merged.push_back(nums2[j]);
            j++;
        }
        
        int n = merged.size();
        
        // Calculate the median
        if (n % 2 == 0) 
        {
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        } 
        else 
        {
            return merged[n/2];
        }
    }
};