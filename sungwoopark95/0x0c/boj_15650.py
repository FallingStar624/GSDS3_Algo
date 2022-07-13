global arr, isused, N, M

def func(cur):
    if cur == M:
        for i in range(M):
            print(arr[i], end=' ')
        print('')
        return
    
    for i in range(1, N+1):
        if not isused[i-1]:
            if (cur >= 1) and (arr[cur-1] > i): 
                continue
            arr[cur] = i
            isused[i-1] = 1
            func(cur+1)
            isused[i-1] = 0


arr = [0 for i in range(10)]
isused = [0 for i in range(10)]

N, M = tuple(input().split(' '))
N, M = int(N), int(M)
func(0)