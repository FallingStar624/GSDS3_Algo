class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        num = 0
        firstchar = 0
        for i in range(len(word)):
            if i == 0:
                if ord(word[i]) < 97: # Capital
                    firstchar = 1    
            if ord(word[i]) < 97 : # upper case
                num += 1
        if num == len(word): # case 1
            return True
        elif num == 0: # case 2
            return True
        elif firstchar == 1 and num == 1: # case 3
            return True
        else:
            return False