n = int(input())
arr = list(map(int, input().split()))
arr.sort()
sum = [0 for _ in range(n)]
sum[0] = arr[0]
for i in range(1, n):
    sum[i] = sum[i-1] + arr[i]
total = 0
for i in range(n):
    total += sum[i]
print(total)