def listTostring(str_list : list)-> str:
    result = ""
    for s in str_list:
        result += s
    return result

def reverse_str(s:str)->str: # s[::-1] 이렇게 해도 되겠네 생각해보니.
    s_list = [0]*len(s)
    for i in range(len(s)):
        s_list[len(s)-1-i] = s[i]
    return listTostring(s_list)

def palindrome(s:str)->bool:
    s_reverse = reverse_str(s)
    if s_reverse == s:
        return True
    else:
        return False
    
def substring(s:str, t:str) -> bool:
    if t in s:
        return True
    else:
        return False

def max_palindromes(s):
    palist = []
    dp = [[0]*len(s) for _ in range(len(s))]
    for i in range(len(s)):
        dp[i][i] = True
        palist.append(s[i:i+1])
    for i in range(len(s)-1,-1,-1):
        for j in range(i+1,len(s)):  
            if s[i] == s[j]:
                if j-i ==1 or dp[i+1][j-1] is True:  # 두글자여서 내부가 없거나 가운데가 palindrome이면... 바깥쪽도 palindrome
                    dp[i][j] = True
                    palist.append(s[i:j+1])
    
    palist = list(set(palist)) # 중복제거
    palist.sort(key=len, reverse = True) # 큰거부터 줄세우기
    palist_pop = palist[:]
    for i in range(len(palist)):
        for j in range(i+1,len(palist)):
            if palist[j] in palist[i] and palist[j] in palist_pop:
                palist_pop.remove(palist[j])

    return palist_pop