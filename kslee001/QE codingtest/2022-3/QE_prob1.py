def substring(s, t):
    if t in s:
        return True
    
def palindrome(s):
    # length 
    length = 0
    for _ in s:
        length += 1
        
    # reverse
    rs = ""
    for idx in range(length-1, -1, -1):
        rs += s[idx]

    return rs == s
    
def max_palindromes(s):
    # length
    length = 0
    for _ in s:
        length += 1
        
    
    res = []
    
    visited = [False for _ in range(length)]
    
    for idx in range(length):
        if visited[idx] == True:
            continue
        cur = s[idx]
        step = length-1-1
        while step > 0 :
            beam = s[idx : idx+step]
            if palindrome(beam):
                res.append(beam)
                visited[idx : idx+step -1] = [True for _ in range(step-1)]
                break
            step -= 1

    return res