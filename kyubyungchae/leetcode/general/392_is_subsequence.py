
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        if len(s) == 0:
            return True

        idx = 0
        for q in t:
            if s[idx] == q:
                idx += 1

            if idx == len(s):
                return True

        return False



if __name__ == '__main__':

    sol = Solution()
    # s = "egg"; t = "add"
    s = "axc"; t = "ahbgdc"

    sl = sol.isSubsequence(s, t)
    print(sl)