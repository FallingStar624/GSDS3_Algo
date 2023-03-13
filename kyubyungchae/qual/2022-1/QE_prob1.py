from typing import List


def substring(s: str, t: str) -> bool:
    """
    (b) Write a function substring(s, t) that 
        checks if the string t is a substring of the string s.
    """
    if len(t) > len(s):
        return False
    
    return t in s

def palindrome(s: str) -> bool:
    """
    (a) Write a function palindrome(s) that checks if the string s is a palindrome.
    """
    return s[::-1] == s


def max_palindromes(s: str) -> List:
    
    ans = []
    for i, ch in enumerate(s):

        for offset in range(len(s), i, -1):

            word = s[i:offset:1]
            if palindrome(word):

                if word not in ans:
                    ans.append(word)
                    
                break
    
    re_ans = []

    for i, word in enumerate(ans):

        isSub = False
        for j, other in enumerate(ans):

            if i == j:
                continue
                
            if word in other:
                isSub = True
                break      
        
        if not isSub:
            re_ans.append(word)

    return re_ans

if __name__ == '__main__':

    # s = "kabccbadzdefgfeda"
    s = "wzabccbazw kabccba dzabccbaza"
    result = max_palindromes(s)
    print(result)
