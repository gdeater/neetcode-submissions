class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def back(start):
            if start == len(nums):
                res.append(nums[:])
                return
            for i in range(start,len(nums)):
                nums[start], nums[i] = nums[i],nums[start]
                back(start + 1)
                nums[start], nums[i] = nums[i], nums[start]
        back(0)
        return res