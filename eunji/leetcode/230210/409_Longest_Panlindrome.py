class Solution:
    def longestPalindrome(self, s: str) -> int:
        alphs = dict()
        for i in list(s):
            if i in alphs:
                alphs[i] += 1
            else:
                alphs[i] = 1

        max_odd = []
        max_even = 0
        for k, v in alphs.items():
            if v % 2 != 0:
                max_odd.append(v)
            else:
                max_even += v
        
        if len(max_odd) > 0:
            return max_even + sum(max_odd) - len(max_odd) + 1
        else:
            return max_even
        
        


if __name__ == '__main__':
    S = Solution()
    q = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"
    print(S.longestPalindrome(q)) # 983
