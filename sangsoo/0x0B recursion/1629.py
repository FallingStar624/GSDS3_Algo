import sys
# print("abc".split())
a, b, c = map(int, sys.stdin.readline().split())

def func(a: int, b: int, c: int) -> int:
    if b == 1: return a % c
    val = func(a, b//2, c) # 파이썬은 //로 해줘야 정수로 나눠짐..
    val = val * val % c
    if (b%2 == 0): return val
    else: return val * a % c

print(func(a, b, c))