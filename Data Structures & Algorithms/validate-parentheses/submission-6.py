class Solution:
    def is_open(self, s:str) -> bool:
        if s == "(" or s == "[" or s == "{":
            return True
        return False

    def is_coresponding(self, s:str, t:str) -> bool:
        if s == "(":
            return t == ")"
        if s == "[":
            return t == "]"
        if s == "{":
            return t == "}"
    def isValid(self, s: str) -> bool:
        stack = []

        if not self.is_open(s[0]) or len(s) % 2 == 1:
            return False

        for i in range(len(s)):
            if self.is_open(s[i]):
                stack.append(s[i])
            else:
                if  len(stack) > 0 and self.is_coresponding(stack[-1], s[i]):
                    stack.pop()
                else:
                    return False


        return len(stack) ==0


        