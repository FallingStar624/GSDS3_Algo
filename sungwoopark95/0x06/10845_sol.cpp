#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000000

class Queue {
    private:
    int size;
    int queue[MAXSIZE];
    int fcursor;
    int bcursor;

    public:
    Queue() { 
        size = 0; 
        fcursor = 0;
        bcursor = 0;
    }

    void push(int x) {
        queue[bcursor] = x;
        size++;
        bcursor++;
    }

    int pop() {
        if (isEmpty()) { 
            return -1; 
        }
        int temp = queue[fcursor];
        queue[fcursor] = 0;
        fcursor++; // 한 칸 뒤로 옮김
        size--; // 크기 하나 줄임
        if (size == 0) { // reinitialize
            fcursor = 0;
            bcursor = 0;
        }
        return temp;
    }

    int getSize() { return size; }

    bool isEmpty() { return (size == 0); }

    int front() { 
        if (isEmpty()) { return -1; }
        else { return queue[fcursor]; }
    }

    int back() { 
        if (isEmpty()) { return -1; }
        else { return queue[bcursor-1]; }
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Queue q;
    int N;
    cin >> N;
    string cmd; 
    int x;
    for (int i=0;i<N;i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            q.push(x);
        } else if (cmd == "pop") {
            cout << q.pop() << "\n";
        } else if (cmd == "front") {
            cout << q.front() << "\n";
        } else if (cmd == "back") {
            cout << q.back() << "\n";
        } else if (cmd == "size") {
            cout << q.getSize() << "\n";
        } else if (cmd == "empty") {
            cout << q.isEmpty() << "\n";
        }
    }
    return 0;
};