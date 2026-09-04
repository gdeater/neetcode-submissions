class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        ans = [0] * len(arr)
        highest = -1
        for i in range(len(arr) - 1, -1, -1):
            ans[i] = highest
            highest = max(arr[i],highest)
        return ans
