N = int(input())
arr = list(map(int, input().split()))
M = int(input())
test = list(map(int, input().split()))

def my_binary_search(target : int, n : int, arr: list) -> bool:
    st = 0 ; en = n -1
    while (st <= en):
        mid = st + (en - st) // 2
        if (target > arr[mid]): st = mid + 1
        elif (target < arr[mid]): en = mid - 1
        else: return 1
    return 0

arr.sort()
for i in range(M):
    print(my_binary_search(test[i], N, arr))
