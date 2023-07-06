import sys
from collections import deque
nm = sys.stdin.readline().split()
# print(nm)
n = int(nm[0])
m = int(nm[1])
findinglist = sys.stdin.readline().split()
dq = deque()
for i in range(1, n+1):
    dq.append(i)
ans = 0
loc = 0
while m:
    # find the index
    for i in range(len(dq)):
        if dq[i] == int(findinglist[loc]):
            idx = i
            break
    while (dq[0] != int(findinglist[loc])):
        if idx < len(dq)-idx:
            dq.append(dq[0])
            dq.popleft()
        else:
            dq.appendleft(dq[-1])
            dq.pop()
        ans += 1
    dq.popleft()
    m -= 1
    loc += 1
print(ans)