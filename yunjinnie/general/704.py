class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # 가운데에서 시작, idx 좌우로 증가시키면서 값 비교
        st = 0
        en = len(nums)-1
        
        def binary(left, right):
            if left<=right:
                mid = left+(right-left)//2
                
                if nums[mid]==target:
                    return mid
                elif nums[mid]>target:
                    return binary(left, mid-1)
                elif nums[mid]<target:
                    return binary(mid+1, right)
            else:
                return -1
        #for i in (len(nums)//2, len(nums)):
        
        ans = binary(st, en)
        
        return ans
            
        # try except?
        # https://cowimming.tistory.com/68