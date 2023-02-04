class Solution:
    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        # Example 1: 
        #   Input: arr = [1,2,3,4,5], k = 4, x = 3
        #   Output: [1,2,3,4]
        # Example 2:
        #   Input: arr = [1,2,3,4,5], k = 4, x = -1
        #   Output: [1,2,3,4]
        if not arr:
            return []
        
        # Find an index pair to start search on both sides
        start, end = 0, len(arr) - 1
        while start + 1 < end:
            mid = (start + end) // 2

            if arr[mid] < x:
                start = mid
            else:
                end = mid

        # Now start and end are used as the probe pointers for 
        # comparing next available elements.
        if start == end:
            end += 1            # keep start and end distinct

        while k > 0:
            if start == -1:
                end += k
                break
            if end == len(arr):
                start -= k
                break
            if x - arr[start] <= arr[end] - x:
                # Always prefer left (smaller) values if distances are the same
                start -= 1
            else:
                end += 1
            k -= 1

        return arr[start+1 : end]
