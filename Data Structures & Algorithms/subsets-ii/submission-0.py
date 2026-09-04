class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = set()

        def dfs(i,sub):
            if i == len(nums):
                res.add(tuple(sub))
                return
            sub.append(nums[i])
            dfs(i+1,sub)
            sub.pop()
            dfs(i+1,sub)
        nums.sort()
        dfs(0,[])
        return list(res)