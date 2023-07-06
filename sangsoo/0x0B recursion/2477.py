n = int(input())

board = [[' ' for _ in range(2300)] for _ in range(2300)]

def func(n:int, x:int, y:int) -> None:
    if n == 1:
        board[x][y] = '*'
        return
    for i in range(3):
        for j in range(3):
            if (i == 1 and j == 1):
                continue
            else:
                func(n // 3, x + n // 3 * i, y + n // 3 * j) # python은 나눌때 / 하나만 쓰면 float이 됨

func(n, 0, 0)
strline = []
for i in range(n):
    s = ''
    for j in range(n):
        s += board[i][j]
    strline.append(s)
for i in range(n):
    print(strline[i])