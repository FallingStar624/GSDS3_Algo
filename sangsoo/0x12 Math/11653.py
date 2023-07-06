n = int(input())
flag = 1
if(n == 1):
    flag = 0
d = 2
if flag:
    while (n != 1):
        while (n % d == 0):
            n /= d
            print(d)
        d += 1