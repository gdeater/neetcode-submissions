class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def count_days(weights, capacity):  # removed self
            d = 1
            total = 0
            for i in weights:
                if total + i <= capacity:  # FIX
                    total += i
                else:
                    d += 1
                    total = i  # FIX
            return d
            
        l, r = max(weights), sum(weights)
        
        while l <= r:
            mid = (l + r) // 2
            if count_days(weights, mid) > days:  # FIX: no self
                l = mid + 1
            else:
                r = mid - 1
                
        return l  # FIX

        