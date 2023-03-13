class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Heap: Lowest / Highest priority node -> Root
        # -> Priority Queue ( abstract data structure ) 
        # Key value relationship (large - small) only between parents - children, not between siblings
        
        #stones.sort(reverse=True)
        #print(stones)
        ans = 0
        
        while len(stones)>1:
            stones.sort(reverse=True)
            if stones[0] == stones[1]:
                del stones[:2]
            else:
                stones[0] = stones[0]-stones[1]
                del stones[1]
            #print(stones)
        #if not stones:
        if len(stones)==0:
            return 0
        ans = stones[0]
        return ans