tmp= list(map(int, input().split()))
N, M = tmp[0], tmp[1]
arr = []
for i in range(N):
    arr.append(int(input()))
arr.sort()
st = en = 0
mn = 2e9+1
while(st < N):
    while(en < N):
        if(arr[en] - arr[st] >= M):
            mn = min(mn, arr[en]- arr[st])
            break
        else:
            en += 1
    st+=1

print(mn)