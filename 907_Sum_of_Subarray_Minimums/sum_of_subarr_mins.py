class Solution:
    def sumSubarrayMins(self, arr: list[int]) -> int:
        def _print(MINS):
            for row in MINS:
                print(row)

        result = 0
        # MINS = [ [0] * len(arr) ] * len(arr)
        # _print(MINS)
        
        # for i, n in enumerate(arr):
        #     print("===")
        #     print("i =", i)
        #     print("n =", n)
        #     MINS[i][i] = n
        #     for j in range(i+1, len(arr)):
        #         print("---")
        #         print("BEFORE: MINS[{}][{}] = {}".format(i, j, MINS[i][j]))
        #         MINS[i][j] = min(MINS[i][j-1], arr[j])
        #         print("AFTER: updated to min(MINS[{}][{}]={}, arr[{}]={}), which is {}"\
        #             .format(i, j-1, MINS[i][j-1], arr[j], j, min(MINS[i][j-1], arr[j])))
        #     print("NOW ROW IS", MINS[i])

        for i, n in enumerate(arr):
            min_so_far = n
            result += n
            for j in range(i+1, len(arr)):
                min_so_far = min(min_so_far, arr[j])
                result += min_so_far

        # _print(MINS)
        return result
        

arr = [11,81,94,43,3]
s = Solution()
print(s.sumSubarrayMins(arr))
