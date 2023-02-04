class Solution:
    def search_iter(self, nums: list[int], target: int) -> int:
        if not nums: return -1
        l, r = 0, len(nums) - 1
        while True:
            if l > r: return -1
            m = (l + r) // 2
            mid_val = nums[m]
            if mid_val == target:
                return m
            elif mid_val < target:
                l = m + 1
            elif mid_val > target:
                r = m - 1
        
    def search(self, nums: list[int], target: int) -> int:
        def search_range(start: int, end: int) -> int:
            if start > end: return -1
            mid = (start + end) // 2
            mid_val = nums[mid]
            if mid_val < target:
                return search_range(mid + 1, end)
            elif mid_val > target:
                return search_range(start, mid - 1)
            else:
                return mid
        return search_range(0, len(nums) - 1)
            