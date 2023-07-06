# N과 M (12)
# N과 M (4) 과 같은데
# 다만 숫자가 1,2,3,.. 이 아니고 주어지는 숫자. + 중복
import sys
n, m = map(int, sys.stdin.readline().split())
arr_v = list(map(int, sys.stdin.readline().split()))
arr = [0 for _ in range(10)]
arr_vv = []
isused = [False for _ in range(10)]
def func(k: int, st: int)->None:
    if(k==m):
        tmp = []
        for i in range(m):
            tmp.append(arr[i])
        if(tmp not in arr_vv):
            arr_vv.append(tmp)
        return
    for i in range(st, n):
        # if(not isused[i]):
        #     isused[i] = True
        arr[k] = arr_v[i]
        func(k+1, i)
            # isused[i] = False
arr_v.sort()
func(0, 0)
arr_vv.sort()
for i in range(len(arr_vv)):
    for j in range(len(arr_vv[i])):
        print(arr_vv[i][j], end = ' ')
    print()
