class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res = ""
        l,r = 0, 0
        len1, len2 = len(word1), len(word2)
        while l < len1 and r < len2:
            res += word1[l] 
            res += word2[r]
            l += 1
            r += 1
        if len1 <= len2:
            res += word2[r:]
        else:
            res += word1[l:]
        return res

        