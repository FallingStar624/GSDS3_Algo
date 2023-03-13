def str_perm(s):
    if s == "":
        return ""
    length = 0
    for c in s:
        length += 1
    if length == 1:
        return s
    
    res = []
    for idx in range(length):
        cur = s[idx]
        resid = s[ : idx] + s[idx+1 : ]
        for p in str_perm(resid):  # recursive call
            res.append(cur + p)            
    return res