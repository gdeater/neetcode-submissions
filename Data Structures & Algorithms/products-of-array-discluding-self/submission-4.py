class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = []
        mul = 1
        if nums.count(0) > 1:
            for i in range(len(nums)):
                ans.append(0)
            return ans

        for i in nums:
            if i != 0:
                mul *= i

        if nums.count(0) == 1:
            for i in range(len(nums)):
                if nums[i] == 0:
                    ans.append(mul)
                else:
                    ans.append(0)
            return ans

        for i in range(len(nums)):
            ans.append(mul//nums[i])
        return ans
