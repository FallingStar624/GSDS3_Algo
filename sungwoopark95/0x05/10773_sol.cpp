#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000000

class Stack {
    private:
    int size;
    int stack[MAX_SIZE];
    public:
    Stack() {
        size = 0;
        for (int i=0;i<MAX_SIZE;i++) {
            stack[i] = 0;
        }
    }

    void push(int x) {
        stack[size] = x;
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
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
        if (size == 0) { return -1; }
        else { return stack[size-1]; }
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Stack s;
    int K; int X;
    cin >> K;
    int cnt = 0;
    for (int i=0;i<K;i++) {
        cin >> X;
        if (X != 0) {
            s.push(X);
            cnt += X;
        } else {
            int temp = s.pop();
            cnt -= temp;
        }
    }

    cout << cnt << "\n";
    return 0;
}