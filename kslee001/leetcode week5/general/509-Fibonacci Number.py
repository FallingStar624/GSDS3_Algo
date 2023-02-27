class Solution:
    def fib(self, n: int) -> int:
        """
        0 : 0
        1 : 1
        2 : f(0) + f(1) = 0 + 1 = 1
        3 : f(1) + f(2) = 1 + 1 = 2
        4 : f(2) + f(3) = 1 + 2 = 3
        5 : f(3) + f(4) = 2 + 3 = 5
        6 : f(4) + f(5) = 3 + 5 = 8
        ...
        n : f(n-2) + f(n-1)
        
        """
        if n <= 1:
            return n

        f2 = 0 # f(n-2) = 0
        f1 = 1 # f(n-1) = 1, initial
        
        cur = 0
        for idx in range(2, n+1):
            cur = f2 + f1 # f(n-2) + f(n-1)
            # swap
            temp = f2
            f2 = f1
            f1 = cur        
            
        return cur