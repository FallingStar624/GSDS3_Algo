def str_perm(s:str):
    # If lst is empty then there are no permutations
    if len(s) == 0:
        return []
 
    # If there is only one character in the given string, only one permutation is possible
    if len(s) == 1:
        return [s]
 
    tmp = [] # empty list that will store current permutation
 
    # Iterate the input and calculate the permutation
    for i in range(len(s)):
       m = s[i]
 
       # Extract s[i] or m from the list. rems is the remaining string
       rems = s[:i] + s[i+1:]
 
       # Generating all permutations where m is first element
       for p in str_perm(rems):
           tmp.append(m + p)
           
    # Remove duplicates
    ans = []
    for item in tmp:
        if item not in ans:
            ans.append(item)
    return ans

if __name__ == "__main__":
    s1 = "abc"
    s2 = "abb"
    s3 = "ab"
    print(str_perm(s1))
    print(str_perm(s2))
    print(str_perm(s3))
