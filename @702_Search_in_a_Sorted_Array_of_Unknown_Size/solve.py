# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader:
#    def get(self, index: int) -> int:

class Solution:
    def search(self, reader: 'ArrayReader', target: int) -> int:
        if reader.get(0) == target: 
            return 0
        
        left, right = 0, 1
        # Find an interval where target must in A[left...right]
        while reader.get(right) < target:
            left = right
            right *= 2
            
        while left <= right:
            mid = (left + right) // 2
            val = reader.get(mid)
            
            if val == target:
                return mid
            if val > target:
                right = mid - 1
            else:
                left = mid + 1
        
        return -1

    def search_using_template(self, reader: 'ArrayReader', target: int) -> int:
        if reader.get(0) == target:
            return 0
        
        # Get a concrete range containing target
        start, end = 0, 1
        while reader.get(end) < target:
            end *= 2

        # Do binary search
        while start + 1 < end:
            mid = (start + end) // 2
            val = reader.get(mid)

            if val < target:
                start = mid
            else: # val >= target
                end = mid

        if reader.get(start) == target:
            return start
        if reader.get(end) == target:
            return end

        return -1

# class Solution:
#     def search(self, reader: 'ArrayReader', target: int) -> int:
#         NOT_FOUND = 2**31 - 1
#         if reader.get(0) > target: return -1
        
#         # Try to find concrete lower and upper bounds
#         i = UPPER = abs(target)                                         # probe index pointer
#         start, end = 0, 0
#         while True:
#             val = reader.get(i)
#             # if end == 0:
#             #     return 0 if val == target else -1
#             if val == NOT_FOUND:
#                 UPPER = i
#                 if start != 0:
#                     i = start + 1
#                 i //= 2
#                 # i = i // 2 if start == 0 else start + i // 2
#             elif val < target:
#                 start = i
#                 i = (i + UPPER) // 2
#             elif val == target:
#                 return i
#             elif val > target:
#                 end = i
#                 break
        
#         # We've got concrete lower and upper bounds start, end where:
#         #   i.e., reader.get(start) < target <= reader.get(end)
#         #   and now we're able to do regular binary search on [start, end]
        
            