class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        dic = {}
        freq = []
        
        for i in words:
            if i not in dic:
                dic[i]=1
            else:
                dic[i] +=1
        # print(dic.items())
        # print(dic.keys())
        # print(dic.values())
        
        dic_sort = sorted(dic.items(), key=lambda x:(-x[1], x[0]))
        # keys -> ascending
        # values -> descending
        
        for i in range(k):
            freq.append(dic_sort[i][0])
        
        #ans = freq[:k+1]
        return freq
        
# https://eunhee-programming.tistory.com/288