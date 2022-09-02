#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;

class Stack {
    size_t s_size;
    int arr[MAX];
    public:
    Stack() { s_size = 0; }
    
    void push(int x) { arr[s_size++] = x; }
    int pop() { 
        if (this->isEmpty()) { return -1; }
        return arr[--s_size]; 
    }
    int getSize() { return s_size; }
    bool isEmpty() { return s_size == 0; }
    int top() {
        if (this->isEmpty()) { return -1; }
        return arr[s_size-1];
    }
};

int N;
string order;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Stack s;
    
    cin >> N;
    while(N--) {
        cin >> order;
        if (order == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        if (order == "top") { cout << s.top() << "\n"; }
        if (order == "size") { cout << s.getSize() << "\n"; }
        if (order == "pop") { cout << s.pop() << "\n"; }
        if (order == "empty") { cout << s.isEmpty() << "\n"; }
    }
    
    return 0;
}