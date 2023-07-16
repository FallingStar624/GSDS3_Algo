n = int(input())
m = {}
for i in range(n):
    name, el = input().split()
    m[name] = el
out = []
for k, v in m.items():
    if v == "enter":
        out.append(k)
out.sort(reverse = True)
for i in range(len(out)):
    print(out[i])