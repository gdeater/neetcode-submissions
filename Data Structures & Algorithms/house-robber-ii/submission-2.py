class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(self.minirob(nums[1:]), self.minirob(nums[:-1]), nums[0])
    def minirob(self,house):
        prev = high = 0
        for cur in house:
            temp = max(high,prev + cur)
            prev = high
            high = temp
        return high