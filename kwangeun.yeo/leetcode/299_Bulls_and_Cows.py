class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        s_cnt = [0 for _ in range(10)]
        g_cnt = [0 for _ in range(10)]
        bulls = 0
        cows = 0
        for s, g in zip(secret, guess):
            if s == g:
                bulls += 1
            s_cnt[int(s)] += 1
            g_cnt[int(g)] += 1
        for s_c, g_c in zip(s_cnt, g_cnt):
            cows += min(s_c, g_c)
        cows -= bulls
        return f"{bulls}A{cows}B"