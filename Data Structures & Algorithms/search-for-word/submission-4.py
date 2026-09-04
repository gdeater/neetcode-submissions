class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        seen = set()
        def dfs(r,c,k):
            if k == len(word):
                return True
            if not(0 <= r < len(board)) or not(0 <= c < len(board[0])) or (r,c) in seen or board[r][c] != word[k]:
                return False
            seen.add((r,c))
            res = dfs(r+1,c,k+1) or dfs(r-1,c,k+1) or dfs(r,c+1,k+1) or dfs(r,c-1,k+1)
            seen.remove((r,c))
            return res
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i,j,0):
                    return True
        return False