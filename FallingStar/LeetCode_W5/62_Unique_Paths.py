from math import factorial

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        a = factorial(m+n-2)
        b = factorial(m-1)
        c = factorial(n-1)
        return (a//b)//c

