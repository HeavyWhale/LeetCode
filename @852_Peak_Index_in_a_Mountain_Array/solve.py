class Solution:
    def peakIndexInMountainArray(self, arr: list[int]) -> int:

        # Naive method: O(n)
        # prev = arr[0]
        # for i, cur in enumerate(arr):
        #     if cur < prev:
        #         return i - 1
        #     prev = cur

        # Binary search: O(log n)
        if not arr:
            return -1
        
        start, end = 0, len(arr) - 1
        while start + 1 < end:
            mid = (start + end) // 2

            # (mid + 1) will always in the bound since the exit condition
            # that is, the upper bound of (mid + 1) is the value of end 
            if arr[mid] > arr[mid + 1]:
                # going downward, the peak is at the left half
                end = mid
            else:
                # going upward, the peak is at the right half
                start = mid

        return start if arr[start] > arr[end] else end
