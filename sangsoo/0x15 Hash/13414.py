K, L = map(int, input().split())
d = {}
for i in range(L):
    id = input()
    d[id] = i
l = []
for k, v in d.items():
    l.append([k, v])

l.sort(key = lambda x : x[1])
s = len(l) if len(l) < K else K
for i in range(s):
    print(l[i][0])