# TLE 
T = int(input())
for _ in range(T):
    k = int(input())
    arr = []
    for _ in range(k):
        c, n = input().split(); n = int(n)
        if (c == "I"): arr.append(n)
        else:
            if len(arr) == 0: continue
            elif (n == 1): arr.remove(max(arr))
            elif (n == -1): arr.remove(min(arr))
    if (len(arr) == 0): print("EMPTY")
    else: print(max(arr), min(arr))
