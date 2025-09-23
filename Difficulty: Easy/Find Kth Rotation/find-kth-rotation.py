class Solution:
    def findKRotation(self, nums):
        index = 1e9
        minn = 1e9
        n = len(nums)
        low = 0
        high = n-1
        
        while low <= high:
            mid = (low + high) // 2
            
            if nums[low] <= nums[mid]:
                if nums[low] < minn:
                    minn = nums[low]
                    index = low
                low = mid + 1
            else:
                if nums[mid] < minn:
                    minn = nums[mid]
                    index = mid
                
                high = mid - 1
        
        return index