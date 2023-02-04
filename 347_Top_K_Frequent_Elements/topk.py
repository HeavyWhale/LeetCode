class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq_table = dict()
        for n in nums:
            freq_table[n] = freq_table.get(n, 0) + 1
        return sorted(freq_table, key=freq_table.get, reverse=True)[:k]

