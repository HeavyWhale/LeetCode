class Solution:
    def containsNearbyAlmostDuplicate(self, nums: list[int], k: int, t: int) -> bool:
        lookup = dict()
        for index, num in enumerate(nums):
            print(lookup)
            for x in range(num-t, num+t+1):
                print("x=",x)
                if x in lookup and index - lookup[x] <= k:
                    return True
            lookup[num] = index
        return False

sol = Solution()
nums = [1,5,9,1,5,9]
k = 2
t = 3
print(sol.containsNearbyAlmostDuplicate(nums,k,t))
