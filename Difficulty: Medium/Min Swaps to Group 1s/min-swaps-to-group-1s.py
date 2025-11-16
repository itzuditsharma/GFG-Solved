#User function Template for python3

class Solution:
    def minSwaps(self, arr):
        n = len(arr)
        k = sum(arr)
        
        if k == 0:
            return -1
        if k == n:
            return 0
            
        curr_ones = sum(arr[0:k])
        max_ones = curr_ones
        
        for i in range(k, n):
            curr_ones += arr[i] - arr[i-k]
            if curr_ones > max_ones:
                max_ones = curr_ones
                
        return k - max_ones