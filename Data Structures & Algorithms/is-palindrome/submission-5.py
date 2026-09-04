class Solution:
    def isPalindrome(self, s: str) -> bool:
        arr = []
        for i in range(len(s)):
            if not (ord(s[i]) in range(48,58) or
                    ord(s[i]) in range(65,91) or
                    ord(s[i]) in range(97,123)):
                continue
            arr.append(s[i].lower())
        s = "".join(arr)
        return s==s[::-1]

        