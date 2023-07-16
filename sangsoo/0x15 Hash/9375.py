from collections import defaultdict

t = int(input())

while(t): 
    n = int(input())
    d = defaultdict(lambda: 1) # value를 1로 초기화 (아예 안입은 경우)
    for i in range(n):
        clothes, type = input().split()
        d[type] +=1
    out = 1
    for k, v in d.items():
        out *= v
    print(out-1)
    t -=1
