class Solution:            
    def decodeString(self, s: str) -> str:
        stack = []
        start = 0
        nums = []
        while (len(s) > start):
            if s[start].isdigit() and len(s) == 1:
                return ""
            if s[start].isdigit():
                num = []
                while s[start].isdigit():
                    num.append(s[start])
                    start += 1
                nums.append(int("".join(num)))
                # print(stack)
                # print(num)
            elif s[start] == "]":
                temp = []
                while(stack[-1] != "["):
                    pop = stack.pop()
                    temp.insert(0, pop)
                stack.pop() # "["
                for i in range(nums.pop()):
                    stack.extend(temp)
                start += 1
            else:
                stack.append(s[start])
                start += 1

        return "".join(stack)          
                
  
if __name__ == '__main__':
    S = Solution()
    graph = s = "3"
    # k = 3
    A = S.decodeString(graph)
    print(A)
            
            