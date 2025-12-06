import heapq
class Solution:
    def mergeArrays(self, mat):
        heap = []
        for i, row in enumerate(mat):
            heapq.heappush(heap, (row[0], i, 0))
        
        heapq.heapify(heap)
        ans = []
        while heap:
            elem, list_idx, elem_idx = heapq.heappop(heap)
            ans.append(elem)
            
            if elem_idx + 1 < len(mat[list_idx]):
                new_elem = mat[list_idx][elem_idx + 1]
                heapq.heappush(heap, (new_elem, list_idx, elem_idx + 1))
                
        return ans