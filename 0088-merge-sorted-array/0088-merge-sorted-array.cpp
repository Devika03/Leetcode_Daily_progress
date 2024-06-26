class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m-1 , b = n -1, c = m + n -1;
        while(a>= 0 && b>= 0){
            if(nums2[b] > nums1[a]){
                nums1[c] = nums2[b];
                b--;
                c--;
            }
            else{
                nums1[c] = nums1[a];
                a--;
                c--;
            }
        }
        
        if(a<0)
        {
        while(b>=0)
        {
            
            nums1[c] = nums2[b];
            b--;
            c--;
        }
        }
        if(b<0)
        {
            while(a>=0)
            {
                nums1[c] = nums1[a];
                a--;
                c--;
            }
        }
        
    }
};