class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        def back(start):
            if start == len(nums) and nums not in res:
                res.append(nums[:])
                return
            for i in range(start,len(nums)):
                nums[start], nums[i] = nums[i], nums[start]
                back(start + 1)
                nums[start],nums[i] = nums[i], nums[start]
        back(0)
        return res