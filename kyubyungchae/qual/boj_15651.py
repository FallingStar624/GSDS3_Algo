class Solution:

    def __init__(self) -> None:
        self.n = 0
        self.m = 0
        self.arr = [0] * 10
        self.isused = [False] * 10

    def func(self, k: int) -> None:
        
        if k == self.m:
            for i in range(self.m):
                print(self.arr[i], end=' ')
            print()
            return
        
        for i in range(1, self.n + 1):
            self.arr[k] = i
            self.func(k+1)


    def main(self):
        n, m = map(int, input().split())
        self.n = n
        self.m = m
        self.func(0)

        return


if __name__ == '__main__':
    sol = Solution()
    sol.main()