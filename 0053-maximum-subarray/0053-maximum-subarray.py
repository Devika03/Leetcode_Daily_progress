class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        current_sum = 0
        overall_max_sum = float('-inf')
        
        for num in nums:
            current_sum = max(current_sum + num, num)
            overall_max_sum = max(overall_max_sum, current_sum)
        
        return overall_max_sum
