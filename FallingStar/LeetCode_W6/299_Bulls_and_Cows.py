from collections import defaultdict

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        s = defaultdict(set)
        g = defaultdict(set)
        for idx, num in enumerate(secret):
            s[num].add(idx)
        for idx, num in enumerate(guess):
            g[num].add(idx)
        x = 0
        y = 0

        for i in range(10):
            curr = str(i)
            s_set = s[curr]
            g_set = g[curr]
            b = 0
            for idx in g_set:
                if idx in s_set:
                    b += 1
            c = min(len(s_set), len(g_set)) - b
            x += b
            y += c

        return f"{x}A{y}B"
