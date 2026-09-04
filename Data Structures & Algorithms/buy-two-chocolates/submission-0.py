class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        pay = prices[0] + prices[1]
        if money >= pay:
            return money - pay
        else:
            return money