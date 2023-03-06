class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        left = 0
        count = {}
        
        for right in range(len(s)):
            count[s[right]] = 1 + count.get(s[right], 0)

            # Check this is a valid window
            # if while condition is true, invalid window
            # otherwise, valid window
            while (right - left + 1) - max(count.values()) > k:
                # invalid, so move the window
                count[s[left]] -= 1 
                left += 1
            
            res = max(res, right - left + 1)
        
        return res
