A = input()
B = input()
C = input()
N = int(A)*int(B)*int(C)
N = str(N)
numdict = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6:0, 7:0, 8:0, 9:0}
for i in range(len(N)):
    numdict[int(N[i])] += 1

values = list(numdict.values())
for i in range(len(values)):
    print(values[i])