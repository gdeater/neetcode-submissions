class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i,j=0,-1

        while numbers[i] + numbers[j] != target:
            total = numbers[i] + numbers[j]
            if total > target:
                j-=1
            else:
                i+=1
        i, j = i+1,len(numbers) + j + 1
        return [i,j]