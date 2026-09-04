class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        ans = []
        for i in range(len(arr) - 1):
            highest = max(arr[i+1:])
            ans.append(highest)
        ans.append(-1)
        return ans
        