N = int(input())
arr = list(map(int, input().split()))
M = int(input())
test = list(map(int, input().split()))

def find_left_idx(target : int, n : int, arr : list):
    st = 0; en = n
    while (st < en):
        mid = st + (en - st) // 2
        if (arr[mid] >= target): en = mid
        else: st = mid + 1
    return st

def find_right_idx(target : int, n : int, arr : list):
    st = 0; en = n
    while (st < en):
        mid = st + (en - st) // 2
        if (arr[mid] > target): en = mid
        else: st = mid + 1
    return st


arr.sort()
for i in range(M):
    print(find_right_idx(test[i], N, arr) - find_left_idx(test[i], N, arr), end = " ")