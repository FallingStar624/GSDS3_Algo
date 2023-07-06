import sys
from collections import deque
# sys.stdin = open("bojinput/10845.txt", "r")
input = sys.stdin.readline
n = int(input())
inlist = []
# for _ in range(n):
#     inlist.append(input().split())
q = deque()
for i in range(n):
    inlist = input().split()
    if inlist[0] == "push":
        q.append(inlist[1])
    elif inlist[0] == "pop":
        if q:
            print(q.popleft())
        else:
            print("-1")
    elif inlist[0] == "size":
        print(len(q))
    elif inlist[0] == "empty":
        if q:
            print("0")
        else:
            print("1")
    elif inlist[0] == "front":
        if q:
            print(q[0])
        else:
            print("-1")
    elif inlist[0] == "back":
        if q:
            print(q[-1])
        else:
            print("-1")