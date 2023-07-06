import sys
N = int(sys.stdin.readline())
out = 0;
for _ in range(N):
    s = sys.stdin.readline().rstrip()
    stk = []
    for i in range(len(s)):
        if not stk:
            stk.append(s[i])
        elif s[i] == 'A':
            if stk[-1] == 'A': 
                stk.pop() #stk  = stk[:-1] 느림 새로운 리스트를 만들고 복사해야함
            else:
                stk.append(s[i])
        elif s[i] == 'B':
            if stk[-1] == 'B':
                stk.pop()
            else:
                stk.append(s[i])
    if not stk: out+= 1
print(out)