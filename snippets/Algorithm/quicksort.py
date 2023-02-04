class Algo:
    def choose_pivot(A: list[int]) -> int:
        """
        Return an index p in A.

        :param A: a list of integers
        :return: an index p in A
        """
        return len(A) - 1

    def partition_range(A: list[int], start: int, end: int, p: int) -> int:
        """
        Rearrange A[start, end] and return pivot-index i so that:
            - the pivot-value v is in A[i],
            - all items in A[start,...,i-1] are ≥ v, and
            - all items in A[i+1,...,end] are ≤ v.
        Idea: Keep swapping the outer-most wrongly-positioned pairs.

        :param A: a list of integers
        :param p: index of the pivot value
        :param start: start index of the range (to be processed)
        :param end: end index of the range (to be processed)
        :return: new index of the pivot value after rearraging
        """
        if not start <= p <= end:
            raise ValueError("pivot index out of range")
        A[end], A[p] = A[p], A[end]
        l, r = start, end - 1
        v = A[end]
        while True:
            while A[l] > v: l += 1
            while r >= l and A[r] < v: r -= 1
            if l >= r: break
            else:
                A[l], A[r] = A[r], A[l]
                l += 1
                r -= 1
        A[end], A[l] = A[l], A[end]
        return l

    def partition(A: list[int], p: int) -> int:
        """
        Rearrange A and return pivot-index i so that:
            - the pivot-value v is in A[i],
            - all items in A[0,...,i-1] are ≥ v, and
            - all items in A[i+1,...,n-1] are ≤ v.
        Idea: Keep swapping the outer-most wrongly-positioned pairs.

        :param A: a list of integers
        :param p: index of the pivot value
        :return: new index of the pivot value after rearraging
        """
        n = len(A)
        if not 0 <= p < n:
            raise ValueError("pivot index out of range")
        A[n - 1], A[p] = A[p], A[n - 1]         # swap pivot value to the end of A
        l, r = 0, n - 2                         # left and right pointers
        v = A[n - 1]                            # for pivot value
        while True:
            while A[l] > v: l += 1              # find an index that its value <= pivot value
            while r >= l and A[r] < v: r -= 1   # find an index that its value >= pivot value
            if l >= r: break                    # break if not valid
            else:
                A[l], A[r] = A[r], A[l]         # swap if valid
                l += 1
                r -= 1
        A[n - 1], A[l] = A[l], A[n - 1]         # place pivot value into correct position
        return l

    def quick_select_range(A: list[int], start: int, end: int, k: int) -> int:
        """
        Return k-th largest element in A.
        Time: O(n^2) but in average Theta(n)

        :param A: a list of integers
        :param k: desired k-th largest element
        :return: k-th largest element in A
        """
        # print("quick_select_range: k = {}, start = {}, end = {}".format(k, start, end))
        if not A:
            raise ValueError("A is not well-defined")
        if not 0 < k <= end - start + 1:
            raise ValueError("k out of range with k = {}, start = {}, end = {}".format(k, start, end))

        p = end                                         # choose a pivot index
        i = Algo.partition_range(A, start, end, p)      # rearrange A based on pivot
        # print("i = {}, A[i] = {}".format(i, A[i]))
        # print("A = {}".format(A))
        order = i + 1 - start
        if order == k:                                  # pivot is exactly k-th largest
            return A[i]
        elif order > k:
            return Algo.quick_select_range(A, start, i - 1, k)
        elif order < k:
            return Algo.quick_select_range(A, i + 1, end, k - order)

    def quick_select(A: list[int], k: int) -> int:
        """
        Return k-th largest element in A.
        Time: O(n^2) but in average Theta(n)

        :param A: a list of integers
        :param k: desired k-th largest element
        :return: k-th largest element in A
        """
        if not A:
            raise ValueError("A is not well-defined")
        if not 0 < k <= len(A):
            raise ValueError("k out of range")

        p = Algo.choose_pivot(A)                # choose a pivot index
        i = Algo.partition(A, p)                # rearrange A based on pivot
        order = i + 1                           # order of pivot in A
        if order == k:                          # pivot is exactly k-th largest
            return A[i]
        elif order > k:
            return Algo.quick_select(A[:i], k)  
        elif order < k:
            return Algo.quick_select(A[i+1:], k - order) # A[3:], 0

A = [ 30, 60, 10, 0, 50, 80, 90, 20, 40, 70 ]   # len = 10
p = len(A)-1 # 70
k = 3 # third largest

_A = A[:]
__A = A[:]

# print("BEFORE:", A)
# Algo.partition_range(_A, 0, len(_A)-1, p)
# print("partition AFTER:", _A)
# Algo.partition_range(__A, p, 0, len(__A)-1)
# print("partition AFTER:", __A)

# print(Algo.quick_select(A, 10)) # expected: 70
print(Algo.quick_select_range(A, 0, len(A) - 1, 2))
