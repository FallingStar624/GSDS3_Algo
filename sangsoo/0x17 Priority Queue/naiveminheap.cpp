// minheap
#include <iostream>
#define MAX_SIZE 100002
using namespace std;

int heap[MAX_SIZE];
int sz = 0; // heap에 들어가는 원소의 수

void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    return;
}


void push(int x){
    heap[++sz] = x;
    int idx = sz;
    while (idx != 1){
        int par = idx/2;
        if(heap[par] <= heap[idx]) break;
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
        int min_child = lc; // 두자식중 작은 index를 담는다.
        if (rc <= sz & heap[rc] < heap[lc]) // rc 가 sz보다 작거나 같다는 것은  rc가 존재함을 의미
            min_child = rc;
        if (heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }    
}

void test(){
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main(void){
    test();
}
