class Solution:
    def decodeString(self, s: str) -> str:
        st = []
        ans = ''
        num = 0
        string = ''
        #while True:
        #for i in range(len(s)):
        for char in s:
            if char.isdigit():
                #num = int(char)
                num = num*10 + int(char)
            elif char=='[': # s[i]
                #i+=1
                #while s[i]==']':
                st.append(string)
                st.append(num)
                string = ''
                num = 0
                #print(st)
            elif char.isalpha():
                string +=char
                # Does string value change after appending?
            elif char==']':
                #print(st)
                # LIFO
                prenum = st.pop()
                prestr = st.pop()
                string = prestr+string*prenum #+=
                #print(string)
            # else:
            #     num = int(i)
            #     i+=1
                
        return string
    
# https://zhenyu0519.github.io/2020/06/20/lc394/