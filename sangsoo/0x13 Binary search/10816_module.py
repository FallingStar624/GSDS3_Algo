import bisect
N = int(input())
arr = list(map(int, input().split()))
M = int(input())
test = list(map(int, input().split()))


arr.sort()
for i in range(M):
    print(bisect.bisect_right(arr, test[i]) - bisect.bisect_left(arr, test[i]), end = " ")