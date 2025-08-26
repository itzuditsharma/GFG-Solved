#User function Template for python3

class Solution:
    # Function to find the subarray with the maximum sum
    def findSubarray(self, arr):
    	maxsum = -1
    	summ = 0
    	ans = []
    	n = len(arr)
    	i = 0
    	
    	for j in range(n):
    	    if arr[j] >=0 :
    	        summ += arr[j]
    	        if summ > maxsum or (summ == maxsum and j-i+1 > len(ans)):
    	            maxsum = summ
    	            ans = arr[i : j + 1]
    	    else:
    	        summ = 0
    	        i = j + 1
    	        
        return ans if ans else [-1]
    	       
    	       
    	        
    	       
    	   
    	       
    	