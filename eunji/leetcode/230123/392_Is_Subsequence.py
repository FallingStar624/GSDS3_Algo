class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
      s = list(s)
      t = list(t)
      start = 0
      if (len(s)==0):
        return True

      for i in t:
        compare = s[start]
        if (compare == i):
          start += 1
        if (start == len(s)):
          return True
      else:
        return False