import heapq
heap = []
heapq.heappush(heap, 50)
heapq.heappush(heap, 10)
heapq.heappush(heap, 20)
print(heap)
heap2 = [50, 10, 20]
heapq.heapify(heap2)
print(heap2)

result = heapq.heappop(heap)
print(result)
print(heap)

result2 = heap[0]

print(result2)
print(heap)

heap_items = [1, 3, 5, 7, 9]
max_heap = []
for item in heap_items:
    heapq.heappush(max_heap, (-item, item))
print(max_heap)
max_item = heapq.heappop(max_heap)[1]
print(max_item)