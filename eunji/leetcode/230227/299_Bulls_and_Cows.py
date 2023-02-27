from collections import Counter 

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0 # same position
        cows = 0 # wrong position
        remain = []
        for i in range(len(secret)):
            if (secret[i] == guess[i]):
                bulls += 1
            else:
                remain.append(secret[i])
                
        for i in range(len(secret)):
            if (secret[i] != guess[i]) and (guess[i] in remain):
                cows += 1
                remain.remove(guess[i])           

        return str(bulls)+"A"+str(cows)+"B"


if __name__ == '__main__':
    S = Solution()
    secret = "1807"
    guess = "7810"
    print(S.getHint(secret, guess)) # 983