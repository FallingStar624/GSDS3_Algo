from typing import List

def palindrome(s:str) -> bool:
    return s == s[::-1]

def substring(s:str, t:str) -> bool:
    return t in s

def max_palindromes(s:str) -> List[str]:
    ## make a list containing every possible palindrome that can be made from s
    paltemp = []
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            chunk = s[i:j]
            if palindrome(chunk):
                paltemp.append(chunk)
    
    ## find the maximal palindromes
    ans = []
    for i in range(len(paltemp)):
        maxpal = paltemp[i]
        for j in range(len(paltemp)):
            if substring(paltemp[j], maxpal):
                maxpal = paltemp[j]
        if maxpal not in ans:
            ans.append(maxpal)

    return ans


if __name__ == "__main__":
    s1 = "kabccbadzdefgfeda"
    s2 = "kabccba dzabccbaza"
    
    print(max_palindromes(s1))
    print(max_palindromes(s2))
