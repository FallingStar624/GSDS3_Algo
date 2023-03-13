def str_perm(s: str):
    ans = []
    n = len(s)
    if n==0:
        return ''
    elif n==1:
        ans.append(s)
        return ans
    else:
        for i in range(n):
            for elem in str_perm(s[:i]+s[i+1:]):
                #print(s[i]+elem)
                #print(len(s))
                #if len(s[i]+elem) == n:
                ans.append(s[i]+elem)

    ans = list(set(ans))
    #print(ans)
    return ans

print(str_perm('abc'))
print(str_perm('abb'))

# https://thispointer.com/generate-all-permutations-of-a-list-in-python/