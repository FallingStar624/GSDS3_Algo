#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000000

class Stack {
    private:
    int size;
    int stack[MAXSIZE];
    public:
    Stack() {
        size = 0;
        for (int i=0;i<MAXSIZE;i++) {
            stack[i] = 0;
        }
    }

    void push(int x) {
        stack[size] = x;
        size++;
    }

    int pop() {
        if (size == 0) {
            return 0;
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
        if (size == 0) { return 0; }
        else { return stack[size-1]; }
    }

    void print() {
        for (int i=0;i<size;i++) {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
};

// int seq[MAXSIZE];
char op[MAXSIZE];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Stack s;
    int n; int x; 
    bool check = true;
    cin >> n;
    int count = 1;
    int opcnt = 0;
    for (int i=0;i<n;i++) {
        cin >> x;
        while (count <= x) {
            s.push(count);
            op[opcnt] = '+';
            count++;
            opcnt++;
        }
        
        // s.print();
        // cout << "x: " << x << "count: "<< count << "top: " << s.getTop() << "\n";
        if (s.getTop() == x) {
            s.pop();
            op[opcnt] = '-';
            opcnt++;
        } else {
            check = false;
            break;
        }
    }

    if (check == false) {
        cout << "NO" << "\n";
    } else {
        for (int i=0;i<opcnt;i++) {
            cout << op[i] << "\n";
        }
    }
    return 0;
}