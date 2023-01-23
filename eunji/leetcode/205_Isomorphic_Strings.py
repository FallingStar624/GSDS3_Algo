class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
      s = list(s)
      t = list(t)
      s_dict = {}
      t_dict = {}
      for i in range(len(s)):
        if s[i] not in s_dict:
          s_dict[s[i]] = [i]
        else:
          s_dict[s[i]].append(i)
      for i in range(len(t)):
        if t[i] not in t_dict:
          t_dict[t[i]] = [i]
        else:
          t_dict[t[i]].append(i)

      if list(s_dict.values()) == list(t_dict.values()): 
        return True
      else:
        False