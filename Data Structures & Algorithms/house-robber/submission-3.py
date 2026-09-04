class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = high = 0
        for cur in nums:
            temp = max(high,prev + cur)
            prev = high
            high = temp
        return high