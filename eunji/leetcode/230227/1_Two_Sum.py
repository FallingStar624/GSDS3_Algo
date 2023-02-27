class Solution:
    def twoSum(self, nums, target):
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                one = nums[i]
                two = nums[j]
                if one + two == target:
                    return [i, j]


if __name__ == '__main__':
    S = Solution()
    s = [0,4,3,0]
    k = 0
    print(S.twoSum(s, k)) # 983