# 299. Bulls and Cows
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
                guess = guess.replace(secret[i], "*", 1)
                secret = secret.replace(secret[i], "#", 1)
        for i in range(len(secret)):
            if secret[i] in guess:
                cows += 1
                guess = guess.replace(secret[i], "*", 1)
        return f"{bulls}A{cows}B"