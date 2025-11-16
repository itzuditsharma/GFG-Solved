class Solution:
    def handleMinSum(self, list1, list2):
        i = len(list1) - 1
        j = len(list2) - 1
        
        carry = 0
        res = []
        
        while i >= 0 or j >= 0 or carry > 0:
            total = carry
            if i >= 0:
                total += list1[i]
            if j >= 0:        
                total += list2[j]
            
            i-=1
            j-=1
            
            res.append(str(total % 10))
            carry = total // 10
        
        while len(res) > 0 and res[-1] == '0':
            res.pop()
        
        res = res[::-1]
        return "".join(res)
            
    
    def minSum(self, arr):
        arr.sort()
        evens = []
        odds = []
        
        for i in range(len(arr)):
            if i % 2 == 0:
                evens.append(arr[i])
            else:
                odds.append(arr[i])
            
        return self.handleMinSum(evens, odds)