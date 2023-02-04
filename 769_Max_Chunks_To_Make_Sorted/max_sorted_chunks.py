from random import shuffle
def getRandomSeq(n):
    ret = list(range(n))
    shuffle(ret)
    return ret

class Solution:
    def my_maxChunksToSorted(self, arr: list[int]) -> int:
        result = 0
        prev_max, cur_max, prev_i = 0, 0, 0
        subarrs = []
        for cur_i,n in enumerate(arr):
            print("=====")
            print("cur_i = {}, n = {}".format(cur_i, n))
            print("cur_max = {}, prev_max = {}".format(cur_max, prev_max))
            if n > cur_max:
                cur_max = n
            if cur_i - prev_i >= cur_max - prev_max:
                result += 1
                subarrs.append(arr[prev_i+1 if prev_i != 0 else 0:cur_i+1])
                prev_i = cur_i
                prev_max = cur_max
            print("cur_max' = {}, prev_max' = {}".format(cur_max, prev_max))
        print("arr =", arr)
        print(subarrs)
        return result
    
    def shit(self, arr: list[int]) -> int:
        ans, ma = 0, 0
        for i, n in enumerate(arr):
            ma = max(ma, n)
            if i == ma:
                ans += 1
        return ans

arr = getRandomSeq(6)
arr = [0,2,1,4,3]
s = Solution()
print("RESULT =", s.shit(arr))
