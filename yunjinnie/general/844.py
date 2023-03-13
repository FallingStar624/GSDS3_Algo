class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # pop
        # st = []
        # for i, j in zip(s, t):
        
        def back(s: str) -> str:
            st = []
            for char in s:
                if char != '#':
                    st.append(char)
                elif char=='#' and st:
                    st.pop()
            return st
                
        if back(s)==back(t):
            return True
        
        return False
    
# https://walkccc.me/LeetCode/problems/0844/?h=844#