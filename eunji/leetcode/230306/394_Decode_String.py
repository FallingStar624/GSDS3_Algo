class Solution:
    def decodeOne(self, one):
        num = int(one[0])
        repeat = one[2:-2]
        ans = num * repeat
        return ans
            
            
    def decodeString(self, s: str) -> str:
        start = 0
        end = len(s)
        ans = []
        ans2 = []
        while (end > start):
            if s[start].isdigit():
              num = []
              while s[start].isdigit():
                  num.append(s[start])
                  start += 1
            elif s[start] == "[" & s[end] == "]":
               self.decodeOne(s, start, end, num)

            elif s[start] != "[" & s[end] == "]":
               end -= 1
            elif s[end].isdigit() == False:
               ans2.append(s[end])
               end -= 1
               
            if s[start].isdigit() == False:
              ans.append(s[start])
              start += 1
            self.decodeOne(s, start, end)
                
