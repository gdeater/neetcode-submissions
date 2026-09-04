class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        total = sum(nums)
        cur_max,cur_min,low,high = 0,0,1e9,-1e9
        for x in nums:
            cur_max = max(cur_max + x, x)
            high = max(high, cur_max)
            cur_min = min(cur_min + x, x)
            low = min(low, cur_min)
        
        if high < 0:
            return high
        
        return max(high, total - low)