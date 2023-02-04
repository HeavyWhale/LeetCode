class Solution:
    def findKthLargest(self, A: list[int], k: int) -> int:
        def partition_range(start: int, end: int, p: int) -> int:
            """
            Rearrange A[start, end] and return pivot-index i so that:
                - the pivot-value v is at A[i],
                - all items in A[start,...,i-1] are ≥ v, and
                - all items in A[i+1,...,end] are ≤ v.
            Idea: Keep swapping the outer-most wrongly-positioned pairs.

            :param p: index of the pivot value
            :param start: starting index of the range (to be processed)
            :param end: ending index of the range (to be processed)
            :return: new index of the pivot value after rearraging
            """
            if not start <= p <= end:
                raise ValueError("pivot index out of range")
            v = A[p]                                    # record pivot val
            A[end], A[p] = A[p], A[end]                 # swap pivot val with end val
            L, R = start, end - 1                       # pointers for swapping
            while True:                                 # keep swapping
                while A[L] > v: L += 1                  # move L pointer to first val <= v
                while R >= L and A[R] < v: R -= 1       # move R pointer to first val >= v
                if L >= R:                              # ? swap is unnecessary
                    break                               
                else:
                    A[L], A[R] = A[R], A[L]             # do the swap
                    L += 1                              # advance L pointer
                    R -= 1                              # advance R pointer (in opposite dir)
            A[end], A[L] = A[L], A[end]                 # place the pivot val in the correct position
            return L
        
        def quick_select_range(start: int, end: int, k: int) -> int:
            """
            Return k-th largest element in A[start, end].
            Time: O(n^2) in the worst case but on average Theta(n)

            :param start: starting index of range to be sorted (included)
            :param end: ending index of range to be sorted (included)
            :param k: desired k-th largest element
            :return: k-th largest element in A
            """
            if not A:
                raise ValueError("A is ill-defined")
            if not 0 < k <= end - start + 1:
                raise ValueError("k out of range")

            p = end                                        # choose a pivot index
            i = partition_range(start, end, p)             # rearrange A based on pivot
            order = i + 1 - start
            if order == k:                                 # pivot is exactly k-th largest
                return A[i]
            elif order > k:
                return quick_select_range(start, i - 1, k)
            elif order < k:
                return quick_select_range(i + 1, end, k - order)
            
        return quick_select_range(0, len(A) - 1, k)
