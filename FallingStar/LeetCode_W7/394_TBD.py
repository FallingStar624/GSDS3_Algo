class Solution:
    def dfs(self, tgt):
        if type(tgt[0])==int:
            num = tgt[0]
        else:
            num = 1
        if '[' in tgt:
            l_idx = tgt.index('[')
            if l_idx > 1:
                num = tgt[l_idx-1]
                return  "".join()+ num * (tgt[1:l_idx] + self.dfs(tgt[l_idx+1:-1]))
            else:
                return num * self.dfs(tgt[2:-1])
        else:
            return "".join(tgt)


    def decodeString(self, s: str) -> str:
        converted = []
        for char in s:
            if char < '[':
                converted.append(int(char))
            else:
                converted.append(char)
        partitioned = [0 for _ in range(len(s))]
        flag = 0
        for idx, char in enumerate(converted):
            if type(char) == int:
                partitioned[idx] = 'i'
            if type(char) == str:
                partitioned[idx] = 's'
            if char == '[':
                flag -= 1
                partitioned[idx] = flag
            elif char == ']':
                flag += 1
                partitioned[idx] = flag
        target = []
        start = 0
        for idx, char in enumerate(partitioned):
            if char == 0:
                target.append(converted[start:idx+1])
                start = idx+1
        if start < len(s):
            target.append(converted[start:])
        ans = [self.dfs(x) for x in target]
        print(ans)
        return 

