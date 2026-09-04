class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        xorr = 0
        for i in nums:
            xorr ^= i
        return xorr