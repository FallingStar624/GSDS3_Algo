# timelimit exceeded
'''
중간중간에 list -> str -> list 하는 과정을 없애면 통과
'''

engstr = input()
n = int(input())
inputeditor = [None for i in range(n)]
for i in range(n):
    inputeditor[i] = input()

cursur = n

def B(cursur, engstr):
    if cursur==0:
        return
    leng = list(engstr)
    leng.pop(cursur-1)
    result = ""
    for s in leng:
        result += s + ""
    cursur -= 1
    return result, cursur

def P(cursur, engstr, new):
    leng = list(engstr)
    leng.insert(cursur+1, new)
    result = ""
    for s in leng:
        result += s + ""
    cursur += 1
    return result, cursur

def L(cursur):
    if cursur > 0:
        cursur -= 1
    return cursur
def D(cursur):
    if cursur < len(n):
        cursur += 1
    return cursur


for order in inputeditor:
    if order == "L":
        cursur = L(cursur)
    elif order == "D":
        cursur = L(cursur)
    elif order == "B":
        engstr, cursur = B(cursur, engstr)
    elif order[0] == "P":
        engstr, cursur = P(cursur, engstr, order[2])
print(engstr)

