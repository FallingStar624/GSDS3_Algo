#include <bits/stdc++.h>
#define MAXSIZE 10000
using namespace std;

class Deque {
    int deque[2*MAXSIZE+1];
    int size, fcursor, bcursor;
public:
    Deque() {
        size = 0;
        fcursor = MAXSIZE; bcursor = MAXSIZE;
    }

    bool isEmpty() {
        if (size == 0) { return true; }
        else { return false; }
    }
    
    int getSize() { return size; }
    
    void push_front(int x) {
        // add an element at the front of the deque
        fcursor--;
        deque[fcursor] = x;
        size++;
    }
    
    void push_back(int x) {
        deque[bcursor] = x;
        bcursor++;
        size++;
    }
    
    int pop_front() {
        if (this->isEmpty()) {
            return -1;
        } 
        int temp = deque[fcursor];
        fcursor++;
        size--;
        return temp;
    }
    
    int pop_back() {
        if (this->isEmpty()) {
            return -1;
        }
        int temp = deque[bcursor-1];
        bcursor--;
        size--;
        return temp;
    }
    
    int front() { 
        if (this->isEmpty()) { return -1; }
        return deque[fcursor];
    }
    
    int back() {
        if (this->isEmpty()) { return -1; }
        return deque[bcursor-1];
    }

    int idx(int x) { 
        for (int i=fcursor;i<bcursor;i++) {
            if (deque[i] == x) {
                return i-fcursor;
            }
        }
        return 0;
    }

    void print() {
        for (int i=fcursor;i<bcursor;i++) {
            cout << deque[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M, x;
    cin >> N >> M;
    Deque d1;
    for (int i=1;i<=N;i++) {
        d1.push_back(i);
    }

    int cnt = 0;
    for (int j=0;j<M;j++) {
        cin >> x;
        while (x != d1.front()) {
            if (d1.idx(x) > (d1.getSize()/2)) { // half보다 뒤에 위치한 값이면
                int temp = d1.pop_back();
                d1.push_front(temp);
                cnt += 1;
            } else {
                int temp = d1.pop_front();
                d1.push_back(temp);
                cnt += 1;
            }
        }
        // 빠져나오면
        d1.pop_front();
    }

    cout << cnt << "\n";

    return 0;
}