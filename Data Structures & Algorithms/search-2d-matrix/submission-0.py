class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        search = []
        for i in matrix:
            search += i
        l, r = 0, len(search) - 1
        while l <= r:
            mid = (l+r) // 2
            if search[mid] == target:
                return True
            if search[mid] > target:
                r = mid - 1
            elif search[mid] < target:
                l = mid + 1
        return False
        