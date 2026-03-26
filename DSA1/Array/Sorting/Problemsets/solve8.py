
from collections import Counter
class Solution:
    def frequencySort(self, nums: list[int]) -> list[int]:
        r = Counter(nums)
        return sorted(nums, key=lambda x: (r[x], -x))