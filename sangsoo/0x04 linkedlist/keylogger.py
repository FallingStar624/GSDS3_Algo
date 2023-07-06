'''
다시 풀기 
'''

import sys

input = sys.stdin.readline

result = ""


def solve(logs):
    left = []
    right = []


    for c in logs:
        if c == "<":
            if len(left) > 0 :
                right.append(left.pop())           
        elif c==">":
            if len(right) > 0 :
                left.append(right.pop())    
        elif c=="-" :
            if len(left) > 0 :
                left.pop()
        else:
            left.append(c)
    answer = left + right[::-1]

    return "".join(answer)

n = int(input())

for _ in range(n):
    logs = input().strip()
    result += solve(logs)
    result +="\n"

print(result)