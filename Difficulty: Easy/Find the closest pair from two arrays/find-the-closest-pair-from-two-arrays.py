#User function Template for python3

class Solution:
    def printClosest (self,arr, brr, n, m, x) : 
        i = 0
        j = m-1
        min_diff = 1e9
        ans_l = -1
        ans_r = -1
        
        while i < n and j >= 0:
            summ = arr[i] + brr[j]
            diff = abs(summ - x)
            
            if diff < min_diff:
                min_diff = diff
                ans_l, ans_r = arr[i],brr[j]
            if summ > x:
                j-= 1
            else:
                i +=1
                
        return (ans_l, ans_r)
            