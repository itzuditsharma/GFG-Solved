#User function Template for python3

import heapq
class Solution:
    def kthSmallest(self, arr,k):
        heap = []

        for num in arr:
            # Push negative value to make a max heap
            heapq.heappush(heap, -num)

            # Maintain only k smallest elements
            if len(heap) > k:
                heapq.heappop(heap)

        # The root of heap is the negative of k-th smallest
        return -heap[0]
        
