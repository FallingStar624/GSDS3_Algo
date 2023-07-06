# input
# boj 10773 제로
K = int(input())
intarr = []
for i in range(K):
    intarr.append(int(input()))

stack = []

for i in range(K):
    if intarr[i] != 0:
        stack.append(intarr[i])
    else: #intarr[i] == 0
        stack.pop()
print(sum(stack))

