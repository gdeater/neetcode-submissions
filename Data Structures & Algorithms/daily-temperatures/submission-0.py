class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = []
        for i in range(len(temperatures)):
            found = False
            for j in range(i,len(temperatures)):
                if temperatures[j] > temperatures[i]:
                    res.append(j - i)
                    found = True
                    break
                elif j == len(temperatures) - 1 and found == False:
                    res.append(0)
        return res

                    
