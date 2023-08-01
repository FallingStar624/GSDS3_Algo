// minheap class ver.
#include <iostream>
#define MAX_SIZE 100002
using namespace std;

void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    return;
}

class Heap{
private:
    int heap[MAX_SIZE];
    int sz;

public:
    Heap() : sz(0) {}
    int getSize(){
        return sz;
    }
    void push(int x){
        heap[++sz] = x;
        int idx = sz;
        while (idx != 1){
            int par = idx/2;
            if(heap[par] >= heap[idx]) break;
            swap(heap[par], heap[idx]);
            idx = par;
        }
    }

    int top(){
        return heap[1];
    }
    void pop(){
        heap[1] = heap[sz--]; // 맨 마지막에 있는 것을 가져옴.
        int idx = 1;
        // 왼쪽 자식의 인덱스(=2*idx)가 size보다 크면 idx는 leaf
        while(2*idx <= sz){
            int lc = 2*idx, rc = 2*idx + 1;
            int max_child = lc; // 두자식중 큰 index를 담는다.
            if (rc <= sz & heap[rc] > heap[lc]) // rc 가 sz보다 작거나 같다는 것은  rc가 존재함을 의미
                max_child = rc;
            if (heap[idx] >= heap[max_child]) break;
            swap(heap[idx], heap[max_child]);
            idx = max_child;
        }    
    }
};


void test(){
    Heap heap;
    heap.push(10); heap.push(2); heap.push(5); heap.push(9); // {10, 2, 5, 9}
    cout << heap.top() << '\n'; // 10
    heap.pop(); // {2, 5, 9}
    heap.pop(); // {2, 5}
    cout << heap.top() << '\n'; // 5
    heap.push(9); heap.push(15); // {5, 9, 15}
    cout << heap.top() << '\n'; // 15
    heap.pop(); // {5, 9}
    cout << heap.top() << '\n'; // 9
}

int main(void){
    test();
}
