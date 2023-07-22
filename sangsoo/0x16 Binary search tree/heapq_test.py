import heapq

heap = []
heapq.heappush(heap, 50)
heapq.heappush(heap, 10)
heapq.heappush(heap, 20)

print(heap)

a = heapq.heappop(heap)
print(a)
print(heap)

_list = [14, 10, 6, 8, 12, 4]
heapq.heapify(_list)
print(_list)

# 최대 힙 max heap ver1.
reverse_sign = lambda x : x*-1
max_heap = list(map(reverse_sign, _list))
heapq.heapify(max_heap)
max_heap = list(map(reverse_sign, max_heap))
print(max_heap)


b = heapq.heappop(max_heap)
print(b)
print(max_heap)

# 최대 힙 max heap ver2. (tuple)
num = [5, 3, 4, 2, 1]
heap = []
for n in num:
    heapq.heappush(heap, (-n, n)) # (우선순위, 값)ㄴ
while heap:
    print(heapq.heappop(heap))

num = [5, 3, 4, 2, 1]
heap = []
for n in num:
    heapq.heappush(heap, (-n, n))
while heap:
    print(heapq.heappop(heap)[1])

visited = [False for _ in range(3)]
print(visited)