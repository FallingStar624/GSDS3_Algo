tmp = list(map(int, input().split()))
N, M = tmp[0], tmp[1]
arr = list(map(int, input().split()))

# prefix sum array
psumarr = [0 for _ in range(N)]
psumarr[0] = arr[0]
for i in range(1, N): psumarr[i] = arr[i] + psumarr[i-1]
st = en = cnt = 0
while(st < N):
    while(en < N):
        partialsum = psumarr[en]-psumarr[st-1] if (st > 0) else psumarr[en]
        if (partialsum == M):
            cnt += 1; st += 1; en += 1 # 파이썬에서도 이렇게 한줄 쓰기 가능하다는 거 오늘 처음 알았음.. !!!
        elif (partialsum > M): break
        else: en += 1
    st += 1
print(cnt)
