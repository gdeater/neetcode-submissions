class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.rob_1(nums[1:]), self.rob_1(nums[:-1]))

    def rob_1(self,nums):
        a, b = 0, 0
        
        for n in nums:
            temp = max(n + a, b)
            a = b
            b = temp
        return b
        