# 509. Fibonacci Number (Top-down DP)
class Solution:
    def fib_helper(self, n : int, memo : list) -> int:
        if n < 2:
            return n
        if memo[n] == 0:
            memo[n] = self.fib_helper(n-1, memo) + self.fib_helper(n-2, memo)
        return memo[n]

    def fib(self, n: int) -> int:
        return self.fib_helper(n, [0 for _ in range(n+1)])
        