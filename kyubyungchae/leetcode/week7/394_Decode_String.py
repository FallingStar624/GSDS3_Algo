
class Solution:
    def decodeString(self, s: str) -> str:

        stack = []
        cur = ''
        k = 0
        for ch in s:
            if ch == '[':
                stack.append((cur, k))
                cur, k = '', 0
            elif ch == ']':
                enc, num_iter = stack.pop()
                cur = enc + num_iter * cur
            elif ch.isdigit():
                k = k * 10 + int(ch)
            else:
                cur += ch
            
        return cur
    
if __name__ == '__main__':
    sol = Solution()

    s = "3[a2[c]]"
    print(sol.decodeString(s))