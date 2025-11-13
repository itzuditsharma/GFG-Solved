import heapq

class Solution:
   def minCost(self, arr):
        heapq.heapify(arr)
        ans = 0
        while len(arr) > 1:
            
            first = heapq.heappop(arr)
            second = heapq.heappop(arr)
            summ = first + second
            ans += summ
            
            heapq.heappush(arr, summ)
        
        return ans
    