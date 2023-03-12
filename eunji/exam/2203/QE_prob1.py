def palindromes(s):
    start = 0
    end = len(s)-1
    is_palindrome = True
    while (start < end):
        if s[start] != s[end]:
            is_palindrome = False
        start += 1
        end -= 1
    # print(is_palindrome)
    return is_palindrome

def substring(s, t):
    is_substring = False
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            if t == s[i:j]:
                is_substring = True
    # print(is_substring)
    return is_substring

def max_palindromes(s):
    palins = []
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            if palindromes(s[i:j]):
                palins.append(s[i:j])
    palins = sorted(list(set(palins)), key=len)
    # print(palins)
    ans = []
    for p in range(len(palins)):
        is_ans = True
        for k in range(p+1, len(palins)): 
            if substring(palins[k], palins[p]):
                is_ans = False
        if is_ans:
            # print(palins[p])
            # print(palins[k])
            # print('---')
            ans.append(palins[p])
    ans = list(set(ans))
    # print(ans)
    return ans
                
if __name__ == '__main__':
    s =  "kabccbadzdefgfeda"
    # palindromes(s)
    max_palindromes(s)
    t2 = "k"
    s2 = "kabccba dzabccbaza"
    # palindromes(s)
    max_palindromes(s2)
    # substring(s2, t2)
    t3 = "a"
    s3 = "bccba"
    max_palindromes(s3)
    # palindromes(s3)
    # substring(s3, t3)
