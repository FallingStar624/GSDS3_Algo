class Solution():
    def __init__(self):
        self.lst = []
        
    def permute(self, string, i, length):
        if i==length: 
            ans =  ''.join(string)
            self.lst.append(ans)
        else: 
            for j in range(i,length): 
                #swap
                string[i], string[j] = string[j], string[i] 
                self.permute(string, i+1, length) # (1) (2)
                string[i], string[j] = string[j], string[i] 
                
def str_perm(s):
    string = list(s)
    length = len(string)
    strings = []
    S  = Solution()
    S.permute(string, 0, length)
    return sorted(list(set(S.lst)))
                 
if __name__ == '__main__':
    s = 'abc'
    A = str_perm(s)
    print(A)
    s = 'abb'
    A = str_perm(s)
    print(A)