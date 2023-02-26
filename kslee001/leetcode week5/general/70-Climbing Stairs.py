class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 :
            return 0
        if n == 1:
            return 1
        a = [False for _ in range(n+1)]

        a[0] = 0
        a[1] = 1
        a[2] = 2

        for i in range(3, n+1):