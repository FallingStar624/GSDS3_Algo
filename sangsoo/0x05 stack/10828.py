# BOJ 10828 스택
# input
import sys

sys.stdin = open('../bojinput/10828.txt', 'r')

n = int(input())
order = []
for i in range(n):
    order.append(input())

stack = []
for i in range(n):
    orderstring = order[i].split(' ')[0]
    # print(f"orderstring:{orderstring}")
    if orderstring == 'push':
        stack.append(order[i].split(' ')[1])
    elif orderstring == 'pop':
        if not stack:
            print(-1)
        else:
            print(stack.pop())
    elif orderstring == 'size':
        print(len(stack))
    elif orderstring == 'empty':
        if not stack:
            print(1)
        else:
            print(0)
    elif orderstring == 'top':
        if not stack:
            print(-1)
        else:
            print(stack[-1])

