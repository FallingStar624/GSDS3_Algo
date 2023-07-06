import sys
while True:
    a = sys.stdin.readline().rstrip() #rstrip으로 해야함
    stk = []
    flag = False
    if a == '.': break
    for i in range(len(a)):
        if (a[i] == '(' or a[i] == '['):
            stk.append(a[i])
        elif a[i] == ')':
            if stk and stk[-1] == '(':
                stk = stk[:-1]
            else:
                print("no")
                flag = True
                break
        elif a[i] == ']':
            if stk and stk[-1] == '[':
                stk = stk[:-1]
            else:
                print("no")
                flag = True
                break
    if flag == True: continue
    else:
        if stk: print("no")
        else: print("yes")