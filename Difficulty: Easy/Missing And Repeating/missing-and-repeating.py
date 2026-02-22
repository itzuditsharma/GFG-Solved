from collections import Counter
class Solution:
    def findTwoElement(self, arr):
        mapp = Counter(arr)
        
        ans = []
        
        for key, val in mapp.items():
            if val >= 2:
                ans.append(key)
                break
        
        for i in range(1, len(arr)+1):
            if i not in mapp.keys():
                ans.append(i)
                break
        
        return ans

