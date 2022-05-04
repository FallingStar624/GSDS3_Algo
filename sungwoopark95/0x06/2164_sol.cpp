#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 2000000

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
        if (this->isEmpty()) { 
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
        if (this->isEmpty()) { return -1; }
        else { return queue[fcursor]; }
    }

    int back() { 
        if (this->isEmpty()) { return -1; }
        else { return queue[bcursor-1]; }
    }

    void print() {
        for (int i=fcursor;i<bcursor;i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Queue q;
    int N;
    cin >> N;
    // initialize
    for (int i=0;i<N;i++) {
        q.push(i+1);
    }

    int front;
    // int trial = 1;
    while (q.getSize() > 1) {
        q.pop(); // throw the first element away
        front = q.pop();
        q.push(front); // move the second element to the end of the queue
        // cout << "After " << trial << " trial" << "\n";
        // q.print();
        // trial++;
    }

    cout << q.back() << "\n";

    return 0;
};