/*class Solution 
{
public:
    int search_prev(vector<int>& nums, int target) 
    {
        int low = 0 ; 
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid]==target) return mid; 
            
            //So we Check both halves of nums . 
            
            if(nums[low]<=nums[mid])
            {
                if(target>= nums[low] && target< nums[mid])
                {
                    high = mid-1;
                }
                else {low=mid+1;}
            }
            else if (nums[mid] < nums[high]) 
            {
                if(target> nums[mid] && target<=nums[high])
                {
                    low = mid+1;
                }
                else { high = mid-1; }
            }
            
            else
            {
                if (nums[low] == nums[mid]) {
                    low++;
                }
                if (nums[high] == nums[mid]) {
                    high--;
            }
            
        }
        }
        return -1;    
    }

    bool search(vector<int>& nums, int target) 
    {
        int result = search_prev(nums,target);
        if(result==-1) return false;
        else return true;
        
    }
};
*/



class Solution {
public:
    int search_prev(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (nums[mid] == target) return mid;
            
            // If the left part is sorted
            if (nums[low] < nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // If the right part is sorted
            else if (nums[mid] < nums[high]) {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            // If nums[low] == nums[mid] == nums[high], skip duplicates
            else {
                if (nums[low] == nums[mid]) low++;
                if (nums[high] == nums[mid]) high--;
            }
        }
        
        return -1;
    }

    bool search(vector<int>& nums, int target) {
        int result = search_prev(nums, target);
        return result != -1;
    }
};







/*
if( nums[0] == target or nums.back() == target ) return true; 
        // this line is redundant it reduces only the worst case when all elements are same to O(1)
        
        const int n = nums.size();
        int l = 0 , h = n-1;
        while( l+1 < n and nums[l] == nums[l+1]) l++;

        // if all elements are same
        if( l == n-1){
            if( nums[0] == target ) return true;
            else return false;
        }
        
        // while last element is equal to 1st element
        while( h >= 0 and nums[h] == nums[0] ) h--;
        int start = l , end = h;
        
        // find the point of pivot ie from where the rotation starts
        int pivot = -1;
        while( l <= h ){
            int mid = l + (h-l)/2;
            if( nums[mid] >= nums[0] ) l = mid+1;
            else {
                pivot = mid;
                h = mid-1;
            }
        }
        
        
        if( pivot == -1 ) l = start , h = end; // if no pivot exits then search space is from start -e end
        else {
            if( target > nums[end] ) l = start , h = pivot-1; // search space second half
            else l = pivot , h = end; // search space first half
        }
        
        // normal binary search
        while ( l <= h ){
            int mid = l + (h-l)/2;
            if( nums[mid] > target ) h = mid-1;
            else if( nums[mid] < target ) l = mid+1;
            else return true;
        }
        
        return false;
*/