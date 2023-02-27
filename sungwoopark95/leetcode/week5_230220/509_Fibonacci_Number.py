class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1

        ans = [0 for _ in range(n+1)]
        ans[0] = 0
        ans[1] = 1
        for idx in range(2, n+1):
            ans[idx] = ans[idx-1] + ans[idx-2]

        return ans[n]
