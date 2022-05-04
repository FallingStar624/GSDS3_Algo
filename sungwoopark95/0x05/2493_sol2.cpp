#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 500000

class Stack {
    private:
    int size;
    int stack[MAXSIZE];
    public:
    Stack() {
        size = 0;
    }

    void push(int x) {
        stack[size] = x;
        size++;
    }

    int pop() {
        if (size == 0) {
            return INT_MIN;
        } else {
            int temp = stack[size-1];
            stack[size-1] = 0;
            size--;
            return temp;
        }
    }

    bool isEmpty() {
        if (size == 0) { return true; }
        else { return false; }
    }

    int getSize() { return size; }

    int getTop() { 
        if (size == 0) { return INT_MIN; }
        else { return stack[size-1]; }
    }

    void print() {
        while (!isEmpty()) {
            cout << this->pop() << " ";
        }
        cout << "\n";
    }
};

int seq[MAXSIZE];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Stack s;
    int N; int tower; 
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> tower;
        s.push(tower);
    }

    int size = s.getSize();
    while (!s.isEmpty()) {
        
    }

    return 0;
}