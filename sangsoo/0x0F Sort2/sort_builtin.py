a = [1, 4, 5, 2, 7]
a.sort()
print(a)

data_list = ['but','i','wont','hesitate','no','more','no','more','it','cannot','wait','im','yours']

#중복 제거
data_list = list(set(data_list))

data_list.sort()
data_list.sort(key=lambda x : len(x), reverse=True)
print(data_list)
data_list.sort(key=lambda x : len(x), reverse=False)
print(data_list)


a = [(1, 2), (5, 1), (0, 1), (5, 2), (3, 0)]

# 앞 인자로 정렬
b = sorted(a)
print(b)

# 비교할 아이템이 요소가 복수 개일 경우, 튜플로 우선순위를 정해줄 수 있다.
# -를 붙이면, 현재와 반대차순으로 정렬된다.

c = sorted(a, key = lambda x : (x[0], -x[1])) 
f = sorted(a, key = lambda x : -x[0])

print(c)
print(f)

# 뒤에 문자 순으로 정렬
s = ['2 A', '1 B', '4 C', '1 A']
s = sorted(s, key=lambda x: (x.split()[1], x.split()[0]))
print(s)
# ['1 A', '2 A', '1 B', '4 C']

from collections import Counter
a_list = ['a', 'b', 'd', 'd', 'b','s']
a_counter = Counter(a_list)
print(a_counter)
a_counter = Counter(a_list).most_common()
print(a_counter)

# 숫자 역순
g = sorted(a_counter, key = lambda x : (-x[1], -ord(x[0])))
print(g)