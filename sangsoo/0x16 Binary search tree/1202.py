'''
failed , solution (https://bio-info.tistory.com/195)
가장 가격이 높은 보석부터 확인하여 보석을 담을 수 있는 가방 중
최대 무게가 가장 작은 가방을 이용해 담는다.
'''
import sys
import heapq
input = sys.stdin.readline
n, k = map(int, input().split())
gems = [list(map(int, input().split())) for _ in range(n)] # gems = [[무게, 가격], [무게, 가격], ...]
bags = [int(input()) for _ in range(k)]
gems.sort() ; bags.sort()
result = 0; tmp = []
for bag in bags: # 가방이 무게가 작은것 부터 정렬되어 있음
    while gems and gems[0][0] <= bag: # 가방의 무게가 보석의 무게보다 크면..
        heapq.heappush(tmp, -gems[0][1])  # tmp에 훔칠 수 있는 보석의 가격을 넣는다.
        heapq.heappop(gems) #gems.pop(0) 으로 하면 시간초과... heappop이 pop보다 빠른듯?
        # gems.pop(0) # 가격을 넣고 가격을 넣은 것을 보석의 list gems에서 pop
    if tmp:
        result -= heapq.heappop(tmp)

print(result) 