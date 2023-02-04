class Solution:
    def findMin(self, nums: list[int]) -> int:
        """
        Example 1:
            Input: nums = [3,4,5,1,2]
            Output: 1
            Explanation: The original array was [1,2,3,4,5] rotated 3 times.
        """
        if not nums:
            return None
        
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = (start + end) // 2
            if nums[mid] < nums[end]:
                # nums[mid...end] is increasing, minimum is at left
                end = mid
            else:
                # nums[mid...end] is not icreasing, minimum is at right
                start = mid
        
        return min(nums[start], nums[end])
