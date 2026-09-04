class Solution:
    def rob(self, nums: List[int]) -> int:
        a,b = 0, 0
        for k in nums:
            temp = max(k + a, b)
            a = b
            b = temp
        return b