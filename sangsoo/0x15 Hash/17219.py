N, M = map(int, input().split())
d = {}
for i in range(N):
    cite, pwd = input().split()
    d[cite] = pwd
for i in range(M):
    cite = input()
    print(d[cite])