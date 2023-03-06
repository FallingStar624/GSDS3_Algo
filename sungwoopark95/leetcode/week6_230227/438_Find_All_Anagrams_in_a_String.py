from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        start, end = ord('a'), ord('z')
        cnt_p = [0] * (end+1 - start)
        cnt_chunk = [0] * (end+1 -start)
        for c in p:
            cnt_p[ord(c)-start] += 1
        print(f"Answer: {cnt_p}")

        for i in range(len(s)):
            chunk = s[i:i+len(p)]
            if i == 0:
                for c in chunk:
                    index = ord(c) - start
                    cnt_chunk[index] += 1
            else:
                index = ord(chunk[-1]) - start
                cnt_chunk[index] += 1
            # print(f"{chunk}\t{cnt_chunk}")
            if len(chunk) == len(p) and cnt_p == cnt_chunk:
                ans.append(i)
            cnt_chunk[ord(chunk[0])-ord('a')] -= 1
        
        return ans


        # # sliding window -> substring with same set of freq of chars
        # ans = []
        # # cnt_s: store frequency of characters in s
        # # cnt_p: store frequency of characters in p
        # cnt_s, cnt_p = [0] * 26, [0] * 26
        # n, m = len(s), len(p)
        # j = 0
        # # count frequency of characters in p
        # for x in p:
        #     cnt_p[ord(x) - ord('a')] += 1
        # for i in range(n):
        #     # add s[j] to the window if the window is not full
        #     while j < n and j - i + 1 <= m:
        #         print(s[j], end='')
        #         cnt_s[ord(s[j]) - ord('a')] += 1
        #         j += 1
        #     # check if both frequency matches
        #     print(cnt_s)
        #     if cnt_s == cnt_p:
        #         # i is the starting index of the window
        #         ans.append(i)
        #     # remove the leftmost element from the window
        #     cnt_s[ord(s[i]) - ord('a')] -= 1
        # return ans
