class Solution:
    def isPossible(self, stalls, dist, k):
        count = 1
        last = stalls[0]
        for i in range(1, len(stalls)):
            if stalls[i] - last >= dist:
                count += 1
                last = stalls[i]
        
            if count >= k:
                return True
                
        return False
                
    
    def aggressiveCows(self, stalls, k):
        n = len(stalls)
        stalls.sort()
        low = 1
        high = stalls[n-1]
        ans = -1
        while low <= high:
            mid = (low + high) // 2
            if self.isPossible(stalls, mid, k) == True:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
            
        return ans
        