'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def helper(self, root, level, res):
        if root == None:
            return 
        
        if len(res) == level:
            res.append(root.data)
        
        self.helper(root.left, level + 1, res)
        self.helper(root.right, level + 1, res)
    
    def LeftView(self, root):
        res = []
        self.helper(root, 0, res)
        return res