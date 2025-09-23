class Solution:
    def lowerbound(self, arr, target):
        low = 0
        high = len(arr) - 1
        ans = len(arr)
        
        while low <= high:
            mid = (low + high) // 2
            
            if arr[mid] >= target:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans
        
    def upperbound(self, arr, target):
        low = 0
        high = len(arr) - 1
        ans = len(arr)
        
        while low <= high:
            mid = (low + high) // 2
            
            if arr[mid] > target:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans
    
    def countFreq(self, arr, target):
        right = self.upperbound(arr, target)
        left = self.lowerbound(arr, target)
        return right - left
        