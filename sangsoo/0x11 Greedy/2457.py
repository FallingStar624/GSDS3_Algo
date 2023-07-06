import sys
n = int(sys.stdin.readline())
flowers = []


# 편의를 위해 100을곱헤 날짜 형식으로 바꿈
for _ in range(n):
    tmp = list(map(int, sys.stdin.readline().split()))
    flowers.append([tmp[0]*100 +tmp[1], tmp[2]*100 +tmp[3]]) # [피는 날, 지는 날]


flowers.sort(key= lambda x : -x[1]) # 늦게 피는 순으로 정렬
flag = 1
if flowers[0][1] < 1201:
    flag = 0
flowers.sort(key = lambda x : x[0]) # 빨리 피는 순으로 정렬
if flowers[0][0] > 301:
    flag = 0


if flag == 1:
    flowers.sort(key = lambda x : (x[0], -x[1])) #빨리 피는 순으로 정렬, 같으면 늦게 지는 순으로 정렬


    cur = 0 # 3월 1일 이전에 피는 꽃중 가장 늦게피는 꽃의 인덱스
    for i in range(1, n):
        flower = flowers[i]
        if flower[0] <= 301:
            if flower[1] > flowers[cur][1]:
                cur = i
    ans = 1
    flag2 = 1
    while(1):
        if flowers[cur][1] > 1130: # 현재 피어있는 꽃이 11월 30일 이후에 지는 경우 반복문 종료
            break
        l = [-1, -1] # 가장 늦게니는 꽃 초기화
        l_idx = -1 # 가장 늦게 지는 꽃의 인덱스  초기화
        for i in range(cur+1, n):
            f = flowers[i]
            if(f[0] <= flowers[cur][1]):# 현재 피어있는 꽃이 지기 전에 피고, 
                if (f[1] > l[1]): # 그 중 가장 늦게 지는 꽃을 찾는다.
                    l = f
                    l_idx = i
        cur = l_idx

        if l[0] == -1: # 현재 피어있는 꽃이 지기전에 피는 꽃이 없는 경우
            print(0)
            flag2 = 0
            break
        else:
            ans += 1
    if flag2 == 1:
        print(ans)


else: # flag == 0 답이 없음
    print(0)