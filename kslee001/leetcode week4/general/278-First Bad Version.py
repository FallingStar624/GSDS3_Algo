# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        """
        - mid 확인
            - fail인 경우 : 이전 버전에서 fail일 가능성 있음
                - 바로 직전 인덱스 확인
                    - 해당 인덱스가 success라면 mid 리턴
                - 그렇지 않은 경우 앞쪽 절반 (start : mid) 진행
                    - end = mid
            - success인 경우 : 반드시 뒷 버전에서 fail
                - 바로 뒤 인덱스 확인
                    - 해당 인덱스가 fail이라면 mid+1 리턴
                - 그렇지 않은 경우 뒤쪽 절반 (mid : end) 진행
                    - start = mid
        """
        start = 0
        end   = n
        
        if n == 1:
            return 1
        
        while(start < end):
            mid = start + (end-start)//2
            
            # mid : fail
            if isBadVersion(mid) == True:
                # mid-1 success -> return mid
                if isBadVersion(mid-1) == False:
                    return mid
                else:
                    end = mid
                    
            # mid : success
            else: # isBadVersion(mid) == False
                # mid+1 fail -> return mid+1
                if isBadVersion(mid+1) == True:
                    return mid+1
                else:
                    start = mid