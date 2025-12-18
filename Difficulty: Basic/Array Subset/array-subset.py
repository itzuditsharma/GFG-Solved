#User function Template for python3
from collections import Counter
class Solution:
    #Function to check if a is a subset of b.
    def isSubset(self, a, b):
        mapp = Counter(a)
        for elem in b:
            if mapp[elem] == 0:
                return False
            mapp[elem] -= 1
        
        return True
    
    
    
    
