import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()  
prefix, suffix = s.split("*")  

for _ in range(n):
    tmp = input().strip() 

    if s == tmp:
        print("DA")
        continue

    if tmp.startswith(prefix) and tmp.endswith(suffix) and len(tmp) >= len(prefix) + len(suffix): # abcbca vs abca
        print("DA")
    else:
        print("NE")
