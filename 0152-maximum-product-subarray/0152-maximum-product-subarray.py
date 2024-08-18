class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        overall_max_prod = float('-inf')
        prod = 1

        # First pass: left to right
        for i in range(len(nums)):
            prod *= nums[i]
            overall_max_prod = max(prod, overall_max_prod)
            if nums[i] == 0:  # Reset product if 0 is encountered
                prod = 1

        prod = 1

        # Second pass: right to left
        for j in range(len(nums) - 1, -1, -1):
            prod *= nums[j]
            overall_max_prod = max(prod, overall_max_prod)
            if nums[j] == 0:  # Reset product if 0 is encountered
                prod = 1

        return overall_max_prod

        