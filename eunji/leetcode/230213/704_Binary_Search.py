class Solution:
    def search(self, nums, target):
        start = 0
        end = len(nums) - 1
        while True:
            middle = (start + end) //2
            if (middle < 0 or middle >= len(nums) or start > end):
                return -1
            if (target < nums[middle]):
                end = middle - 1
            elif (nums[middle] < target):
                start = middle + 1
            elif (nums[middle] == target):
                return middle


if __name__ == '__main__':
    S = Solution()
    q = [-1,0,3,5,9,12]
    target = 2
    print(S.search(q, target)) # 983
