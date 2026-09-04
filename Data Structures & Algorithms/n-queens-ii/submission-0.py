class Solution:
    def totalNQueens(self, n: int) -> int:
        col = set()
        anti = set()
        dia = set()

        def back(r):
            if r == n:
                return 1
            cnt = 0
            for c in range(n):
                if not (c in col or (r - c) in dia or (r + c) in anti):
                    col.add(c)
                    anti.add(r + c)
                    dia.add(r - c)

                    cnt += back(r + 1)

                    col.remove(c)
                    anti.remove(r + c)
                    dia.remove(r - c)
            return cnt
        return back(0)

