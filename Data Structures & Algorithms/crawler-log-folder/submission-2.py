class Solution:
    def minOperations(self, logs: List[str]) -> int:
        stack = 0
        for i in logs:
            if i == "./":
                continue
            elif i == "../" and stack > 0:
                stack -= 1
            elif stack == 0 and i == "../":
                continue
            else:
                stack += 1
        return stack

        