class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        st = []
        ans = [0] * n
        ans[n-1] = -1
        st.append(arr[n-1])
        
        for i in range(n-2, -1, -1):
            
            while st and st[-1] <= arr[i]:
                st.pop()
            
            if len(st) == 0:
                ans[i] = -1
            else:
                ans[i] = st[-1]
            
            st.append(arr[i])
            
        return ans
        