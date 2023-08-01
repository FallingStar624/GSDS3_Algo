#include <iostream>
#define MAX_SIZE 100002
using namespace std;
int n;

void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    return;
}

class Heap{
private:
    int heararr[MAX_SIZE];
    int sz;

public:
    Heap() : sz(0) {}
    int getSize(){
        return sz;
    }
    void push(int x){
        heararr[++sz] = x;
        int idx = sz;
        while (idx != 1){
            int par = idx/2;
            if(heararr[par] >= heararr[idx]) break;
            swap(heararr[par], heararr[idx]);
            idx = par;
        }
    }

    int top(){
        return heararr[1];
    }
    void pop(){
        heararr[1] = heararr[sz--]; // 맨 마지막에 있는 것을 가져옴.
        int idx = 1;
        // 왼쪽 자식의 인덱스(=2*idx)가 size보다 크면 idx는 leaf
        while(2*idx <= sz){
            int lc = 2*idx, rc = 2*idx + 1;
            int max_child = lc; // 두자식중 큰 index를 담는다.
            if (rc <= sz & heararr[rc] > heararr[lc]) // rc 가 sz보다 작거나 같다는 것은  rc가 존재함을 의미
                max_child = rc;
            if (heararr[idx] >= heararr[max_child]) break;
            swap(heararr[idx], heararr[max_child]);
            idx = max_child;
        }    
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Heap heap;
    while(n--){
        int x;
        cin >> x;
        if(x == 0){
            if (heap.getSize() > 0){
                cout << heap.top() << '\n';
                heap.pop();
            }
            else cout << 0 << '\n';
        }
        else{
            heap.push(x);
        }

    }
}