import sys
input = sys.stdin.readline

s = input()[:-1]
n = len(s)
c_alp = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

i = 0 ; cnt = 0
while(True):
    if(i >= n): break
    if(s[i:i+2] in c_alp or s[i:i+3] == 'dz='):
        cnt += 1
        if s[i:i+2] in c_alp:
            i += 2
        else:
            i += 3
    else:
        i += 1
        cnt += 1
print(cnt)