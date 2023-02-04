class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:
        if not nums: return
        self.mergesort(nums)
        return nums
     
    def quicksort(self, nums: list[int]) -> None:
        def quicksort_range(start: int, end: int) -> None:
            if start >= end: return                 
            
            pivot = nums[(start + end) // 2]        # select pivot in the middle
            l, r = start, end                       # pointers for iterating the list
            
            # Bring values <= pivot to the left of pivot and
            #   values >= poivot to the right of pivot
            while l <= r:                           # ? valid pointers
                while l <= r and nums[l] < pivot: l += 1    # find a value that is >= pivot from left
                while l <= r and nums[r] > pivot: r -= 1    # find a value that is <= pivot from right
                if l <= r:                          # ? valid pointers
                    nums[l], nums[r] = nums[r], nums[l]
                    l += 1
                    r -= 1
            
            # now left > right
            quicksort_range(start, r)
            quicksort_range(l, end)
        quicksort_range(0, len(nums) - 1)

    def mergesort(self, nums: list[int]) -> None:
        if len(nums) > 1:
            mid = len(nums) // 2
            L, R = nums[:mid], nums[mid:]
            self.mergesort(L)
            self.mergesort(R)

            i = j = k = 0

            while i < len(L) and j < len(R): 
                if L[i] < R[j]: 
                    nums[k] = L[i] 
                    i+=1
                else: 
                    nums[k] = R[j] 
                    j+=1
                k+=1
 
            while i < len(L): 
                nums[k] = L[i] 
                i+=1
                k+=1

            while j < len(R): 
                nums[k] = R[j] 
                j+=1
                k+=1
