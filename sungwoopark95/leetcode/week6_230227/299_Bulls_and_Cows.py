class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows = 0, 0
        length = len(secret)
        freq, compare = dict(), dict()
        unmatched = []
        for c in secret:
            freq[c] = 1 + freq.get(c, 0)
            compare[c] = 0

        for i in range(length):
            if secret[i] == guess[i]:
                bulls += 1
                compare[guess[i]] += 1
            else:
                unmatched.append(i)

        for idx in unmatched:
            if guess[idx] in secret and compare[guess[idx]] < freq[guess[idx]]:
                cows += 1
                compare[guess[idx]] += 1
        
        return f"{bulls}A{cows}B"
