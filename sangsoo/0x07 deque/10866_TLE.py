# time limit exceeded
from collections import deque

n = int(input())
dq = deque()
while (n):
    q = input().split()
    if (q[0] == "push_back"):
        val = q[1]
        dq.append(val)
    elif (q[0] == "push_front"):
        val = q[1]
        dq.appendleft(val)
    elif (q[0] == "pop_front"):
        if dq:
            print(dq.popleft())
        else:
            print(-1)
    elif (q[0] == "pop_back"):
        if dq:
            print(dq.pop())
        else:
            print(-1)
    elif (q[0] == "front"):
        if dq:
            print(dq[0])
        else:
            print(-1)
    elif (q[0] == "back"):
        if dq:
            print(dq[-1])
        else:
            print(-1)
    elif (q[0] == "size"):
        print(len(dq))
    elif (q[0] == "empty"):
        if dq:
            print(0)
        else:
            print(1)
    n -= 1