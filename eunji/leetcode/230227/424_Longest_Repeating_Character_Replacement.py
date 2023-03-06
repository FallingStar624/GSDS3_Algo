from collections import Counter 

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        st = 0
        en = 0
        ans = 0
        count = Counter()
        while (en < len(s)):
            # print(st, en)
            count[s[en]] += 1
            most = count.most_common(1)[0][1] # max(Counter.values())
            # print(count)
            required = en - st - most + 1 # "AABBA"
            # print(required)
            if required > k:
                count[s[st]] -= 1
                st += 1
            else:
                if ans < (en - st + 1):
                    ans = (en - st + 1)
            en += 1
        return ans


if __name__ == '__main__':
    S = Solution()
    s = "ABAA"
    k = 0
    print(S.characterReplacement(s, k)) # 983






        