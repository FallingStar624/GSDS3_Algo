import sys
n = int(sys.stdin.readline())
def func(n:int, a:int, b:int, c:int)->None: # n개의 원판 a->b
    if (n > 1):
        func(n-1, a, c, b)
        print(a, b)
        func(n-1, c, b, a)
    else:
        print(a, b)

print((1<<n)-1)
func(n, 1, 3, 2)
