class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        longest, counter = 0, 0
        for i in nums:
            if i == 1:
                counter += 1
                if counter >= longest:
                    longest = counter
            else:
                counter = 0
        return longest
        