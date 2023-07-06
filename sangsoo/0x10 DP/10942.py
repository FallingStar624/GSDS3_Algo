import sys
N = int(input())
arr = list(map(int, input().split()))
dp = [[0 for i in range(N+1)] for i in range(N+1)]

# 길이가 1인 경우
for i in range(N):
    dp[i][i] = 1
    # 길이가 2인 경우
    if(i != 0):
        if(arr[i] == arr[i-1]):
            dp[i-1][i] = 1

# 길이가 3이상이 경우
for i in range(N):  # 수열의 길이 i
    for j in range(N-i): # 수열의 시작 index 지점
        if ((arr[j] == arr[j+i]) and (dp[j+1][i+j-1]==1)):
            dp[j][j+i] = 1

M = int(input())
for i in range(M):
    s, e = map(int, sys.stdin.readline().split())
    print(dp[s-1][e-1])

