n, m = map(int, input().split())
si_dict = {}
is_dict = {}
idx = 1

def isNumber(s : str) -> bool:
    for i in range(len(s)):
        if not (48 <= ord(s[i]) <= 57): # 아스키 코드상 숫자가 아니면
            return False
    return True

for i in range(n):
    name = input()
    si_dict[name] = idx
    is_dict[idx] = name
    idx += 1
for i in range(m):
    in_str = input()
    if (isNumber(in_str)):
        num = int(in_str)
        print(is_dict[num])
    else:
        print(si_dict[in_str])
