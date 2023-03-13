def palindrome(s: str):
    n = len(s)
    if n==0:
        return False
    elif n==1:
        return True
    for i in range(n//2):
        if s[i]!=s[n-i-1]:
            return False
    #print('True')
    return True

def substring(s: str, t: str):
    # 0 - 0:3
    # 3 - 3:6
    tmp = ''
    for i in range(len(s)-len(t)+1):
        tmp=s[i:i+len(t)]
        #print(tmp)
        if tmp==t:
            #print('True')
            return True
    return False

def max_palindromes(s:str):
    ans = []
    pld = []
    n = len(s)
    for i in range(n):
        for j in range(n, -1, -1): # from n
            if palindrome(s[i:j]):
                pld.append(s[i:j])
    pld = list(set(pld))
    pld.sort(key=len, reverse=True)
    #print(pld)

    ans = pld[:]
    for i in range(len(pld)):
        for j in range(len(pld)):
            if substring(pld[i], pld[j]) and pld[i]!=pld[j]:
                #if pld[i] in ans:
                if pld[j] in ans:
                    ans.remove(pld[j])
                
    print(ans) ##
    return ans

#palindrome('abcba')
#substring('abcba', 'abc')
max_palindromes('kabccbadzdefgfeda')
max_palindromes('kabccba dzabccbaza')

# https://hyunsix.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%ED%8C%B0%EB%A6%B0%EB%93%9C%EB%A1%AC-Python
