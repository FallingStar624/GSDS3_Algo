class Solution1:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        return self.fib(n - 1) + self.fib(n - 2)


class Solution2:
    def fib(self, n: int) -> int:
        res = [i if i <= 1 else 0 for i in range(n + 1)]
        for i in range(2, n + 1):
            res[i] = res[i - 1] + res[i - 2]
        return res[n]