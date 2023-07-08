tmp = list(map(int, input().split()))
N, S = tmp[0], tmp[1]
arr = list(map(int, input().split()))
prefixsum = [0 for _ in range(N)]

mn = 1e5+1
prefixsum[0] = arr[0]
for i in range(1, N):
    prefixsum[i] = arr[i] + prefixsum[i-1]

st = en = 0
while (st < N):
    while (en < N):
        partialsum = prefixsum[en]-prefixsum[st-1] if st > 0 else prefixsum[en] # C++과 다르게 파이썬에서 arr[-1]하면 뒤에 index를 인식한다. 
        if(partialsum >= S):
            mn = min(mn, en-st)
            break
        en += 1
    st += 1
if(mn == 1e5+1):
    print(0)
else:
    print(mn+1)