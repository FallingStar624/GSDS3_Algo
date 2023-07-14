

def foo(s):

    pos = {}
    for idx, ch in enumerate(s):
        pos[idx] = ch
    
    t = s[0]
    visited = [(0, t)]
    
    idx = 1
    while pos:
        print(idx in pos.keys(), idx)
        curChar = ''
        if idx in pos.keys():
            curChar = pos[idx]
            visited.append((idx, curChar))
            if abs(visited[-1][0] - idx) == 0:
                idx += 1
                visited.pop()
                continue
            elif abs(visited[-1][0] - idx) > 1:
                t += curChar
                pos.pop(idx)
        
        idx += 1

        if idx == len(s):

            idx = 0

        if idx > 1000:
            print(t)
            break


    print(pos)





if __name__ == '__main__':
    s = "abcde" #"adbec"
    # s = "abc" #""
    # s = "" #""
    # s = "abccde" #"cacebd"
    # s = "abcdcef" # cacfbed
    # s = "ab"

    d = {}
    d[0] = 'a'
    print(d.pop(0))
    print(bool(d))
    print(foo(s))

