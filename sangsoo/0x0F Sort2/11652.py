import math
n = int(input())
a = []
for i in range(n):
    tmp = int(input())
    a.append(tmp)

a.sort()
cnt, mxcnt = 0, 0
mxval = -math.inf

for i in range(n):
    if (i==0 or a[i-1]== a[i]): cnt += 1
    else:
        if (cnt > mxcnt):
            mxcnt = cnt
            mxval = a[i-1]
        cnt = 1
if (cnt > mxcnt): mxval = a[n-1]
print(mxval)