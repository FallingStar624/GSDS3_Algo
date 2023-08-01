# max heap
import sys
MAX_SIZE = 100002
input = sys.stdin.readline
class Heap():
    def __init__(self):
        self.size = 0
        self.heaparr = [0 for _ in range(MAX_SIZE)]
    
    def push(self, x: int) -> None:
        self.size += 1
        self.heaparr[self.size] = x
        idx = self.size
        while(idx != 1):
            par = idx//2
            if(self.heaparr[par] >= self.heaparr[idx]): break
            self.heaparr[par], self.heaparr[idx] = self.heaparr[idx], self.heaparr[par]
            idx = par
    def top(self) -> int:
        return self.heaparr[1]
    def pop(self) -> int:
        self.heaparr[1] = self.heaparr[self.size]
        self.size -= 1
        idx = 1
        while(2*idx <= self.size):
            lc = 2*idx; rc = 2*idx +1
            max_child = lc
            if(rc <= self.size and self.heaparr[rc] > self.heaparr[lc]):
                max_child = rc
            if (self.heaparr[idx] >= self.heaparr[max_child]): break
            self.heaparr[idx], self.heaparr[max_child] = self.heaparr[max_child], self.heaparr[idx]
            idx = max_child

n = int(input())
heap = Heap()
for _ in range(n):
    x = int(input())
    if(x == 0):
        if(heap.size > 0):
            print(heap.top())
            heap.pop()
        else:
            print(0)
    else:
        heap.push(x)
