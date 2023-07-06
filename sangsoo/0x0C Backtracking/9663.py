import sys
n = int(input())
cnt = 0
isused1 = [False for _ in range(16)]
isused2 = [False for _ in range(30)]
isused3 = [False for _ in range(30)]

def func(r: int)-> None:
    global cnt
    if (r==n):
        cnt += 1
        return;
    for c in range(n):
        if ((isused1[c]) + (isused2[r+c]) + isused3[r-c+n-1]) == 0:
            isused1[c] = 1; isused2[r+c] = 1; isused3[r-c+n-1] = 1
            func(r+1)
            isused1[c] = 0; isused2[r+c] = 0; isused3[r-c+n-1] = 0

func(0)
print(cnt)