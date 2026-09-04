class Solution:
    def is_Anagrams(self, s:str, t:str) -> bool:
        if len(s) != len(t):
            return False
        mp1 = {}
        mp2 = {}
        for i in range(len(s)):
            mp1[s[i]] = mp1.get(s[i],0) + 1
            mp2[t[i]] = mp2.get(t[i],0) + 1
        return mp1 == mp2

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 0:
            return []
        if len(strs) == 1:
            return [strs]
        ans=[]
        while len(strs) > 0:
            res = []
            pivot = strs[0]
            res.append(pivot)
            del strs[0]
            j = 0
            while j < len(strs):
                word = strs[j]
                if self.is_Anagrams(pivot, word):
                    res.append(word)
                    strs.pop(j)
                else:
                    j += 1
            ans.append(res)
        return ans