class Solution:
    def merge(self, low, mid, high, arr):
        temp = []
        count = 0
        left = low
        right = mid+1
        
        while left <= mid and right <= high:
            if arr[left] <= arr[right]:
                temp.append(arr[left])
                left+=1
            else:
                temp.append(arr[right])
                count += (mid - left) + 1
                right += 1
        
        while left <= mid:
            temp.append(arr[left])
            left+=1
        
        while right <= high:
            temp.append(arr[right])
            right+=1
        
        arr[low : high+1] = temp
        
        return count
    
    def mergeSort(self, low, high, arr):
        count = 0
        if low >= high:
            return count
            
        mid = (low + high)//2
        
        count += self.mergeSort(low, mid, arr)
        count += self.mergeSort(mid+1, high, arr)
        count += self.merge(low, mid, high, arr)
        
        return count
    
    def inversionCount(self, arr):
        n =  len(arr)
        return self.mergeSort(0, n-1, arr)