import heapq
class Solution:
    def thirdLargest(self,arr):
        n = len(arr)
        if n < 3:
            return -1
            
        heap = []
        for i in range(n):
            heapq.heappush(heap, arr[i])
            if len(heap) > 3:
                heapq.heappop(heap)
        
        return heap[0]