class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(self.minirob(nums[1:]), self.minirob(nums[:-1]), nums[0])
    def minirob(self,houses):
        prev = high = 0
        for cur in houses:
            temp = max(high, cur + prev)
            prev = high
            high = temp
        return high 
        