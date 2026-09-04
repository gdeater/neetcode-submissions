class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        memo = {}
        high = 0
        def bfs(x, y):
            if (x, y) in memo:
                return memo[(x, y)]
            cur = matrix[x][y]
            ans = 1
            if x + 1 < len(matrix) and matrix[x + 1][y] > cur:
                ans = max(ans, 1 + bfs(x + 1, y))
            if x - 1 >= 0 and matrix[x - 1][y] > cur:
                ans = max(ans, 1 + bfs(x - 1, y))
            if y + 1 < len(matrix[0]) and matrix[x][y + 1] > cur:
                ans = max(ans, 1 + bfs(x, y + 1))
            if y - 1 >= 0 and matrix[x][y - 1] > cur:
                ans = max(ans, 1 + bfs(x, y - 1))
            memo[(x, y)] = ans
            return ans
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                high = max(high, bfs(i, j))
        return high