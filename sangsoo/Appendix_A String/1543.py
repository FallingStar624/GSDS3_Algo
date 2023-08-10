import sys
input = sys.stdin.readline
s1 = input()[:-1]
s2 = input()[:-1]
n1 = len(s1)
n2 = len(s2)
i = 0; cnt = 0
while(True):
    if(i > n1-n2): break
    if(s1[i:i+n2]==s2):
        i += n2
        cnt += 1
    else:
        i += 1

print(cnt)