class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        pos = dict()
        for index, num in enumerate(nums):
            if (num in pos) and (index - pos[num] <= k):
                return True
            pos[num] = index
        return False
