class Solution:
    def isPossible(self, arr, max_pages, k):
        count = 1
        summ = 0
        for i in range(len(arr)):
            if summ + arr[i] <= max_pages:
                summ += arr[i]
            else:
                count +=1
                summ = arr[i]
            
        if count <= k:
            return True
        
        return False
    
    def findPages(self, arr, k):
        low = max(arr)
        high = sum(arr)
        if k > len(arr):
            return -1
            
        ans = -1
        while low <= high:
            mid = (low + high) // 2
            
            if self.isPossible(arr, mid, k) == True:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
            
        return ans
