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
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Deque d;
    int N;
    cin >> N;
    string cmd;
    for (int i=0;i<N;i++) {
        cin >> cmd;
        if (cmd == "push_front") {
            int x;
            cin >> x;
            d.push_front(x);
        } else if (cmd == "push_back") {
            int x;
            cin >> x;
            d.push_back(x);
        } else if (cmd == "pop_front") {
            cout << d.pop_front() << "\n";
        } else if (cmd == "pop_back") {
            cout << d.pop_back() << "\n";
        } else if (cmd == "size") {
            cout << d.getSize() << "\n";
        } else if (cmd == "empty") {
            cout << d.isEmpty() << "\n";
        } else if (cmd == "front") {
            cout << d.front() << "\n";
        } else if (cmd == "back") {
            cout << d.back() << "\n";
        }
    }
    
    return 0;
}