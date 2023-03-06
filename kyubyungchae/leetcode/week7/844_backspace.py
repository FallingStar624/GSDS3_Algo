
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        
        tmp_s = ''
        for i, ch in enumerate(s):

            if ch == '#':
                tmp_s = tmp_s[:len(tmp_s)-1]
                continue

            tmp_s += ch

        tmp_t = ''
        for i, ch in enumerate(t):

            if ch == '#':
                tmp_t = tmp_t[:len(tmp_t)-1]
                continue

            tmp_t += ch

        print(tmp_s, tmp_t)
        return tmp_s == tmp_t

    

if __name__ == '__main__':
    sol = Solution()
    # s = "ab#c"
    # t = "ad#c"
    s = "ab##";t = "c#d#"
    s = "a#c";t = "b"
    print(sol.backspaceCompare(s, t))
    